#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double chargeRate(double kg, bool express, bool insured) {
    double amount = 40.0 + kg * 12.0;
    if (express) amount += 25.0;
    if (insured) amount += 15.0;
    return amount;
}

// Integer argument means weight in grams.
double charge(int grams) {
    return chargeRate(grams / 1000.0, false, false);
}

// Double argument means weight in kilograms; options have defaults.
double charge(double kg, bool express = false, bool insured = false) {
    return chargeRate(kg, express, insured);
}

double charge(const Parcel& p) {
    return chargeRate(p.weightKg, p.express, p.insured);
}

int main() {
    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    cout << "charge(2.0) = " << charge(2.0) << '\n';
    cout << "charge(2, true) = " << charge(2, true) << '\n';
    cout << "charge(2.0, true, true) = " << charge(2.0, true, true) << '\n';
    Parcel p{1.5, false, true};
    cout << "charge(Parcel) = " << charge(p) << '\n';
}
