#include <iostream>
#include <stdexcept>
#include <string>
class BillingError : public std::runtime_error {
public: using std::runtime_error::runtime_error;
};
class InvalidCharge : public BillingError {
public: using BillingError::BillingError;
};
class ClaimError : public BillingError {
public: using BillingError::BillingError;
};
double calculate(double charge) {
    if (charge < 0) throw InvalidCharge("negative charge");
    return charge;
}
void auditAndRethrow(double billed, double cover) {
    try {
        if (billed > cover) throw ClaimError("claim exceeds cover");
        std::cout << "claim accepted\n";
    } catch (const ClaimError& e) {
        std::cerr << "audit: " << e.what() << '\n';
        throw;
    }
}
int main() {
    try { (void)calculate(-10); }
    catch (const BillingError& e) { std::cout << "billing error: " << e.what() << '\n'; }
    try { auditAndRethrow(60000, 50000); }
    catch (const ClaimError& e) { std::cout << "user message: " << e.what() << '\n'; }
}
