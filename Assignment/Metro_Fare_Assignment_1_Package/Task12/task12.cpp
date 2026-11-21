#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>
enum class Zone : std::size_t { Inner=0, Middle=1, Outer=2, Airport=3 };
constexpr std::array<long long,4> BASE_FARE_PAISE{1000,2000,3000,6000};
constexpr long long MIN_BALANCE_PAISE=5000;
constexpr int PEAK_PERCENT=20, WEEKEND_DISCOUNT_PERCENT=10;
bool isPeak(int h){return (h>=8&&h<10)||(h>=17&&h<20);}
class Pass {
    std::array<bool,4> covered{};
public:
    Pass(Zone a,Zone b){
        if(a==b) throw std::invalid_argument("Choose two distinct zones");
        covered.at(static_cast<std::size_t>(a))=true;
        covered.at(static_cast<std::size_t>(b))=true;
    }
    bool covers(Zone z)const{return covered.at(static_cast<std::size_t>(z));}
};
class FareCalculator {
public:
    static long long calculate(Zone z,int hour,bool weekend){
        auto i=static_cast<std::size_t>(z);
        if(i>=BASE_FARE_PAISE.size()||hour<0||hour>23)
            throw std::invalid_argument("Invalid zone or hour");
        long long base=BASE_FARE_PAISE[i];
        if(weekend) return base-base*WEEKEND_DISCOUNT_PERCENT/100;
        return isPeak(hour)?base+base*PEAK_PERCENT/100:base;
    }
};
class SmartCard {
    long long balancePaise;
    const Pass* monthlyPass;
public:
    explicit SmartCard(long long opening,const Pass* pass=nullptr)
        :balancePaise(opening),monthlyPass(pass){
        if(opening<0) throw std::invalid_argument("Negative balance");
    }
    bool canTravel(Zone z,long long f)const{
        if(monthlyPass && monthlyPass->covers(z)) return true;
        return f>=0 && balancePaise-f>=MIN_BALANCE_PAISE;
    }
    bool deduct(Zone z,long long f){
        if(monthlyPass && monthlyPass->covers(z)) return true;
        if(!canTravel(z,f)) return false;
        balancePaise-=f; return true;
    }
    long long balance()const{return balancePaise;}
};
int main(){
    std::cout<<"Airport off-peak: "<<FareCalculator::calculate(Zone::Airport,12,false)<<" paise\n";
    std::cout<<"Airport peak: "<<FareCalculator::calculate(Zone::Airport,8,false)<<" paise\n";
    std::cout<<"Airport weekend at peak hour: "<<FareCalculator::calculate(Zone::Airport,8,true)<<" paise\n";
    Pass pass(Zone::Inner,Zone::Middle);
    SmartCard card(10000,&pass);
    std::cout<<"Covered Middle accepted: "<<std::boolalpha
             <<card.deduct(Zone::Middle,2400)<<", balance: "<<card.balance()<<"\n";
    std::cout<<"Uncovered Airport accepted: "<<card.deduct(Zone::Airport,6000)
             <<", balance: "<<card.balance()<<"\n";
}