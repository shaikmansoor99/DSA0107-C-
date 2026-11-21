#include <chrono>
#include <iostream>
struct Counter {
    int v=0;
    inline Counter& operator++(){++v;return *this;}
    inline Counter operator++(int){Counter old=*this;++v;return old;}
};
volatile int sink=0;
int main(){
    const int N=10000000;
    Counter a,b;
    auto s=std::chrono::steady_clock::now();
    for(int i=0;i<N;++i) ++a;
    auto e=std::chrono::steady_clock::now();
    for(int i=0;i<N;++i) b++;
    auto f=std::chrono::steady_clock::now();
    sink=a.v+b.v;
    std::cout<<"prefix_ms="<<std::chrono::duration<double,std::milli>(e-s).count()<<'\n';
    std::cout<<"postfix_ms="<<std::chrono::duration<double,std::milli>(f-e).count()<<'\n';
}
