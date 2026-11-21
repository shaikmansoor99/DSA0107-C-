#include <iostream>
#include <stdexcept>
constexpr long long MIN_BALANCE_PAISE = 5000;
long long proceduralFare(long long base, bool peak) {
    return peak ? base + base * 20 / 100 : base;
}
bool proceduralCanTravel(long long balance, long long f) {
    return f >= 0 && balance - f >= MIN_BALANCE_PAISE;
}
bool proceduralDeduct(long long& balance, long long f) {
    if (!proceduralCanTravel(balance,f)) return false;
    balance -= f; return true;
}
class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial) {
        if (initial < 0) throw std::invalid_argument("Negative opening balance");
    }
    long long balance() const { return balancePaise; }
    bool canTravel(long long f) const {
        return f >= 0 && balancePaise - f >= MIN_BALANCE_PAISE;
    }
    bool deduct(long long f) {
        if (!canTravel(f)) return false;
        balancePaise -= f; return true;
    }
    bool recharge(long long amount) {
        if (amount <= 0) return false;
        balancePaise += amount; return true;
    }
};
int main() {
    long long pBalance=10000;
    const long long f=proceduralFare(3000,true);
    std::cout << "Procedural accepted: " << std::boolalpha
              << proceduralDeduct(pBalance,f) << ", balance paise: " << pBalance << '\n';
    SmartCard card(10000);
    std::cout << "OOP accepted: " << card.deduct(f)
              << ", balance paise: " << card.balance() << '\n';
}