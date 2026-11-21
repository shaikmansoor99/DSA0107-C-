#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    explicit Money(long long totalPaise, bool raw):paise(raw?totalPaise:totalPaise*100){}
    Money operator+(const Money& rhs) const { return Money(paise+rhs.paise,true); }
    Money operator-(const Money& rhs) const { return Money(paise-rhs.paise,true); }
    Money& operator+=(const Money& rhs) { paise+=rhs.paise; return *this; }
    bool operator==(const Money& rhs) const { return paise==rhs.paise; }
    bool operator<(const Money& rhs) const { return paise<rhs.paise; }
    friend ostream& operator<<(ostream& os,const Money& m) {
        long long a=m.paise<0?-m.paise:m.paise;
        if(m.paise<0) os<<'-';
        return os<<"Rs "<<a/100<<'.'<<setw(2)<<setfill('0')<<a%100<<setfill(' ');
    }
    friend istream& operator>>(istream& is,Money& m) {
        long long rupees; int p;
        if(is>>rupees>>p) m.paise=rupees*100+p;
        return is;
    }
    long long rawPaise() const { return paise; }
};
int main() {
    Money a(120,75), b(79,25);
    Money c=a+b;
    cout<<c<<'\n'<<boolalpha<<(c==Money(200))<<'\n';
    Money carry=Money(0,75)+Money(0,50);
    cout<<"Carry: "<<carry<<'\n';
    cout<<"Negative subtraction: "<<Money(1,0)-Money(2,0)<<'\n';
    Money bill(100,0); bill+=a; bill+=b;
    cout<<"Bill total: "<<bill<<'\n';
}
