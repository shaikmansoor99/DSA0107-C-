#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bill {
public:
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
};
class OPBill : public Bill {
    double amount;
public:
    explicit OPBill(double a) : amount(a) {}
    double total() const override { return amount; }
    std::string type() const override { return "OP"; }
};
class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& bill) const = 0;
    virtual std::string name() const = 0;
};
class SelfPay : public Payer {
public:
    double amountCovered(const Bill&) const override { return 0.0; }
    std::string name() const override { return "SelfPay"; }
};
class Insurance : public Payer {
    double coverLimit, copayPercent;
public:
    Insurance(double limit, double copay) : coverLimit(limit), copayPercent(copay) {}
    double amountCovered(const Bill& b) const override {
        const double eligible = std::min(b.total(), coverLimit);
        return eligible * (1.0 - copayPercent / 100.0);
    }
    std::string name() const override { return "Insurance"; }
};
class GovernmentScheme : public Payer {
    double packageRate;
public:
    explicit GovernmentScheme(double rate) : packageRate(rate) {}
    double amountCovered(const Bill& b) const override {
        return std::min(b.total(), packageRate);
    }
    std::string name() const override { return "GovernmentScheme"; }
};
class CorporateTieUp : public Payer {
    double percentage;
public:
    explicit CorporateTieUp(double pct) : percentage(pct) {}
    double amountCovered(const Bill& b) const override {
        return b.total() * percentage / 100.0;
    }
    std::string name() const override { return "CorporateTieUp"; }
};
int main() {
    OPBill bill(50000);
    std::vector<std::unique_ptr<Payer>> payers;
    payers.push_back(std::make_unique<SelfPay>());
    payers.push_back(std::make_unique<Insurance>(40000, 10));
    payers.push_back(std::make_unique<GovernmentScheme>(30000));
    payers.push_back(std::make_unique<CorporateTieUp>(70));
    for (const auto& p : payers)
        std::cout << p->name() << " covers " << p->amountCovered(bill) << '\n';
}
