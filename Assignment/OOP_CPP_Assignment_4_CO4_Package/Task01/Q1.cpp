#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;
    static constexpr double DA_RATE = 0.42;
public:
    Staff(string n,int i,double b):name(move(n)),id(i),basic(b){}
    virtual double pay() const = 0;
    virtual void print() const {
        cout << name << " (" << id << ") pay=Rs " << pay() << '\n';
    }
    virtual ~Staff() = default;
};
class Professor : public Staff {
    double research;
public:
    Professor(string n,int i,double b,double r):Staff(move(n),i,b),research(r){}
    double pay() const override { return basic + basic*DA_RATE + research; }
};
class LabAssistant : public Staff {
public:
    LabAssistant(string n,int i,double b):Staff(move(n),i,b){}
    double pay() const override { return basic + basic*DA_RATE; }
};
class GuestFaculty : public Staff {
    double hours, rate;
public:
    GuestFaculty(string n,int i,double h,double r):Staff(move(n),i,0),hours(h),rate(r){}
    double pay() const override { return hours*rate; }
    void print() const override {
        cout << name << " (" << id << ") guest pay=Rs " << pay() << '\n';
    }
};
int main() {
    vector<unique_ptr<Staff>> payroll;
    payroll.push_back(make_unique<Professor>("Anita",101,50000,8000));
    payroll.push_back(make_unique<LabAssistant>("Bala",102,30000));
    payroll.push_back(make_unique<GuestFaculty>("Charan",103,40,900));
    for (const auto& person : payroll) person->print();
}
