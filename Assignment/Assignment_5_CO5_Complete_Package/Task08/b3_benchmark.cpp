#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <random>
#include <string>
#include <variant>
#include <vector>
struct VirtualBill {
    virtual ~VirtualBill() = default;
    virtual double total() const = 0;
};
struct VOP : VirtualBill { double a,b; VOP(double x,double y):a(x),b(y){} double total()const override{return a+b;} };
struct VIP : VirtualBill { double a; int d; VIP(double x,int y):a(x),d(y){} double total()const override{return a*d;} };
struct SwitchBill { int type; double a,b; int days; };
double switchTotal(const SwitchBill& x) { switch(x.type){case 0:return x.a+x.b;case 1:return x.a*x.days;default:return 0;} }
using VariantBill = std::variant<VOP,VIP>;
double variantTotal(const VariantBill& v) { return std::visit([](const auto& x){return x.total();},v); }
template<class F> double measure(F fn) {
    auto s=std::chrono::steady_clock::now(); volatile double sink=fn();
    auto e=std::chrono::steady_clock::now(); (void)sink;
    return std::chrono::duration<double>(e-s).count();
}
int main() {
    for (std::size_t n : {1000u,1000000u,10000000u}) {
        std::vector<std::unique_ptr<VirtualBill>> vv; vv.reserve(n);
        std::vector<SwitchBill> ss; ss.reserve(n);
        std::vector<VariantBill> va; va.reserve(n);
        for(std::size_t i=0;i<n;++i) {
            if(i%2==0){vv.push_back(std::make_unique<VOP>(100,20));ss.push_back({0,100,20,0});va.emplace_back(VOP(100,20));}
            else {vv.push_back(std::make_unique<VIP>(50,3));ss.push_back({1,50,0,3});va.emplace_back(VIP(50,3));}
        }
        double sumV=0, sumS=0, sumA=0;
        double tv=measure([&]{double s=0;for(auto& p:vv)s+=p->total();sumV=s;return s;});
        double ts=measure([&]{double s=0;for(auto& x:ss)s+=switchTotal(x);sumS=s;return s;});
        double ta=measure([&]{double s=0;for(auto& x:va)s+=variantTotal(x);sumA=s;return s;});
        std::cout<<"n="<<n<<" virtual_s="<<tv<<" switch_s="<<ts<<" variant_s="<<ta
                 <<" totals="<<sumV<<","<<sumS<<","<<sumA
                 <<" agree="<<((sumV==sumS && sumS==sumA)?"yes":"NO")<<'\n';
    }
    for(int pct : {0,1,50}) {
        constexpr int n=1000000;
        std::vector<int> data(n,100);
        for(int i=0;i<n*pct/100;++i)data[i]=-1;
        auto ret=measure([&]{long long ok=0;for(int x:data){if(x<0)continue;++ok;}return double(ok);});
        auto exc=measure([&]{long long ok=0;for(int x:data){try{if(x<0)throw std::invalid_argument("bad");++ok;}catch(const std::exception&){} }return double(ok);});
        std::cout<<"invalid="<<pct<<"% return_s="<<ret<<" exception_s="<<exc<<'\n';
    }
    std::cout<<"sizeof(SwitchBill)="<<sizeof(SwitchBill)<<" sizeof(VariantBill)="<<sizeof(VariantBill)
             <<" sizeof(VirtualBill*)="<<sizeof(VirtualBill*)<<'\n';
}
