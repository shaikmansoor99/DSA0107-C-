#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Bill {
protected: std::string patient;
public:
    explicit Bill(std::string p):patient(std::move(p)){}
    virtual ~Bill()=default;
    virtual double total()const=0;
    virtual std::string type()const=0;
};
class OPBill:public Bill {
    double consultation,tests;
public:
    OPBill(std::string p,double c,double t):Bill(std::move(p)),consultation(c),tests(t){}
    double total()const override{return consultation+tests;}
    std::string type()const override{return "OP";}
};
class InPatientBill:public Bill {
    int days;double rate,procedure;
public:
    InPatientBill(std::string p,int d,double r,double pr):Bill(std::move(p)),days(d),rate(r),procedure(pr){}
    double total()const override{return days*rate+procedure;}
    std::string type()const override{return "IP";}
};
// Extension 1: new bill type; existing classes remain unchanged.
class TelemedicineBill:public Bill {
    double platformFee,consultationFee;
public:
    TelemedicineBill(std::string p,double f,double c):Bill(std::move(p)),platformFee(f),consultationFee(c){}
    double total()const override{return platformFee+consultationFee;}
    std::string type()const override{return "TELEMEDICINE";}
};
class Payer {
public: virtual ~Payer()=default; virtual double cover(double amount)const=0; virtual std::string name()const=0;
};
class SelfPay:public Payer {
public:double cover(double)const override{return 0;}std::string name()const override{return "SelfPay";}
};
// Extension 2: new payer; existing payer classes are unchanged.
class EmployeeBenefit:public Payer {
    double percent;
public:explicit EmployeeBenefit(double p):percent(p){}
    double cover(double amount)const override{return amount*percent/100.0;}
    std::string name()const override{return "EmployeeBenefit";}
};
int main(){
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OPBill>("Asha",500,1000));
    bills.push_back(std::make_unique<InPatientBill>("Bala",2,2000,5000));
    bills.push_back(std::make_unique<TelemedicineBill>("Charan",100,700));
    std::vector<std::unique_ptr<Payer>> payers;
    payers.push_back(std::make_unique<SelfPay>());
    payers.push_back(std::make_unique<EmployeeBenefit>(80));
    for(const auto& b:bills) {
        std::cout<<b->type()<<" total="<<b->total()<<'\n';
        for(const auto& p:payers) std::cout<<"  "<<p->name()<<" covers "<<p->cover(b->total())<<'\n';
    }
}
