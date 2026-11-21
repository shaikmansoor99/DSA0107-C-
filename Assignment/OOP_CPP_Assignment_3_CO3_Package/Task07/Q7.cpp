#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double re, im;
public:
    Complex():re(0),im(0){}
    Complex(double real):re(real),im(0){}
    Complex(double real,double imag):re(real),im(imag){}
    double real() const{return re;}
    double imag() const{return im;}
    double magnitude() const{return hypot(re,im);}
    Complex operator+(const Complex& z) const{return {re+z.re,im+z.im};}
    Complex operator-(const Complex& z) const{return {re-z.re,im-z.im};}
    Complex operator*(const Complex& z) const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
    Complex operator/(const Complex& z) const {
        double den=z.re*z.re+z.im*z.im;
        if(den==0.0) throw domain_error("division by zero impedance");
        return {(re*z.re+im*z.im)/den,(im*z.re-re*z.im)/den};
    }
    bool operator==(const Complex& z) const {
        const double eps=1e-9;
        return fabs(re-z.re)<eps && fabs(im-z.im)<eps;
    }
    friend ostream& operator<<(ostream& os,const Complex& z){
        os<<z.re<<(z.im<0?" - ":" + ")<<fabs(z.im)<<'j'; return os;
    }
};
int main(){
    const double pi=acos(-1.0), f=50.0, w=2*pi*f, L=0.1, C=100e-6;
    Complex R(10,0), ZL(0,w*L), ZC(0,-1.0/(w*C));
    Complex series=R+ZL+ZC;
    cout<<"R = "<<R<<"\nL = "<<ZL<<"\nC = "<<ZC<<'\n';
    cout<<"Series impedance = "<<series<<", magnitude = "<<series.magnitude()<<'\n';
    Complex z1(10,5),z2(20,-3);
    Complex parallel=(z1*z2)/(z1+z2);
    cout<<"Parallel impedance = "<<parallel<<", magnitude = "<<parallel.magnitude()<<'\n';
    try { Complex zero; Complex bad=z1/zero; cout<<bad; }
    catch(const domain_error& e){cout<<"Safe error: "<<e.what()<<'\n';}
}
