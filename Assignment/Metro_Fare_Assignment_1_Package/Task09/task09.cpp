#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE=5000;
constexpr int PEAK_PERCENT=20;
bool isPeak(int hour) { return (hour>=8 && hour<10)||(hour>=17 && hour<20); }
bool parseZone(const std::string& s, Zone& z) {
    if(s=="Inner"){z=Zone::Inner;return true;}
    if(s=="Middle"){z=Zone::Middle;return true;}
    if(s=="Outer"){z=Zone::Outer;return true;}
    return false;
}
long long baseFare(Zone z) {
    switch(z) {
        case Zone::Inner:return 1000;
        case Zone::Middle:return 2000;
        case Zone::Outer:return 3000;
    }
    return -1;
}
long long calculateFare(Zone z,int hour) {
    long long b=baseFare(z);
    if(b<0||hour<0||hour>23)return -1;
    return isPeak(hour)?b+b*PEAK_PERCENT/100:b;
}
bool canTravel(long long balance,long long fare) {
    return fare>=0 && balance-fare>=MIN_BALANCE_PAISE;
}
bool validRecharge(long long amount) { return amount > 0; }
int main() {
    struct Test{const char* zone;int hour;long long expected;};
    const Test tests[]={{"Inner",7,1000},{"Inner",8,1200},{"Middle",10,2000},
      {"Middle",17,2400},{"Outer",19,3600},{"Outer",20,3000},{"Unknown",12,-1}};
    bool allPass=true;
    for(const auto& t:tests) {
        Zone z{}; long long actual=-1;
        if(parseZone(t.zone,z)) actual=calculateFare(z,t.hour);
        bool pass=actual==t.expected; allPass=allPass&&pass;
        std::cout<<t.zone<<" "<<t.hour<<" expected "<<t.expected
                 <<" actual "<<actual<<" "<<(pass?"PASS":"FAIL")<<'\n';
    }
    long long balance=10000, exactFare=5000;
    std::cout<<"Exact Rs 50 remaining accepted: "<<std::boolalpha
             <<canTravel(balance,exactFare)<<'\n';
    std::cout << "Negative recharge rejected: " << (!validRecharge(-1000)) << std::endl;
    std::istringstream invalidHour("letters"); int parsedHour = 0;
    std::cout << "Letters rejected as hour: " << (!static_cast<bool>(invalidHour >> parsedHour)) << std::endl;
    long long total=1000+1200+2000+2400+3600;
    std::cout<<"Five-journey total paise: "<<total<<" (Rs "
             <<std::fixed<<std::setprecision(2)<<static_cast<double>(total)/100.0<<")\n";
    std::cout<<"All fare test cases passed: "<<allPass<<'\n';
}
