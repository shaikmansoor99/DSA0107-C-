#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(std::string p) : patient(std::move(p)) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
    virtual void print() const {
        std::cout << type() << " " << patient << ": " << total() << '\n';
    }
};
class OutPatientBill final : public Bill {
    double consultation, tests;
public:
    OutPatientBill(std::string p, double c, double t)
        : Bill(std::move(p)), consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OP"; }
};
class InPatientBill final : public Bill {
    int days; double perDay, procedures, medicines;
public:
    InPatientBill(std::string p, int d, double rate, double proc, double meds)
        : Bill(std::move(p)), days(d), perDay(rate), procedures(proc), medicines(meds) {}
    double total() const override { return days * perDay + procedures + medicines; }
    std::string type() const override { return "IP"; }
};
class DayCareBill final : public Bill {
    double packagePrice;
public:
    DayCareBill(std::string p, double price) : Bill(std::move(p)), packagePrice(price) {}
    double total() const override { return packagePrice; }
    std::string type() const override { return "DAYCARE"; }
};
class EmergencyBill final : public Bill {
    double baseCharge, perMinute; int minutes;
public:
    EmergencyBill(std::string p, double base, double rate, int mins)
        : Bill(std::move(p)), baseCharge(base), perMinute(rate), minutes(mins) {}
    double total() const override { return baseCharge + perMinute * minutes; }
    std::string type() const override { return "EMERGENCY"; }
};
int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<OutPatientBill>("Ravi", 500, 1200));
    bills.push_back(std::make_unique<InPatientBill>("Meena", 3, 2500, 40000, 1500));
    bills.push_back(std::make_unique<DayCareBill>("Arun", 18000));
    bills.push_back(std::make_unique<EmergencyBill>("Sara", 2000, 150, 30));
    double grandTotal = 0;
    for (const auto& b : bills) { b->print(); grandTotal += b->total(); }
    std::cout << "Day total: " << grandTotal << '\n';
}
