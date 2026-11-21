#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const { return 3.5; }
    virtual void describe() const { cout<<"Account rate="<<rate()<<'\n'; }
    virtual ~Account(){cout<<"~Account ";}
};
class SeniorAccount : public Account {
    unique_ptr<double[]> history;
public:
    SeniorAccount():history(make_unique<double[]>(100)){}
    double rate() const override { return 4.0; }
    void describe() const override {cout<<"SeniorAccount rate="<<rate()<<'\n';}
    ~SeniorAccount() override {cout<<"~SeniorAccount ";}
};
int main(){
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());
    for(const auto& a:accounts) a->describe();
    cout<<"rates: ";
    for(const auto& a:accounts) cout<<a->rate()<<' ';
    cout<<"\nDestroying polymorphic accounts: ";
    accounts.clear();
    cout<<"\nSlicing demonstration: ";
    SeniorAccount senior;
    Account sliced=senior;
    cout<<sliced.rate()<<" (base part only)\n";
}
