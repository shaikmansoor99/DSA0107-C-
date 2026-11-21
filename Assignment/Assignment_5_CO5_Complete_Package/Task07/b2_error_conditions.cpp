#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <vector>
void validate(double amount) {
    if (amount < 0) throw std::invalid_argument("negative");
    if (amount > 1e6) throw std::out_of_range("too large");
    std::cout << "ok ";
}
void process(double amount) {
    try { validate(amount); }
    catch (const std::out_of_range& e) {
        std::cout << "[log " << e.what() << "] ";
        throw;
    }
}
class ClaimError : public std::runtime_error {
public: using std::runtime_error::runtime_error;
};
double approve(double billed, double cover) {
    if (billed < 0 || cover < 0) throw std::invalid_argument("negative amount");
    if (billed > cover) throw ClaimError("exceeds cover");
    return billed;
}
double settle(double billed, double cover) {
    try { return approve(billed, cover); }
    catch (const ClaimError& e) { std::cout << "audit: " << e.what() << '\n'; throw; }
}
struct Tracked { ~Tracked() { std::cout << "Tracked destroyed\n"; } };
int main() {
    for (double a : {100.0, -5.0, 2e6}) {
        try { process(a); std::cout << "done "; }
        catch (const std::exception& e) { std::cout << "caught " << e.what() << ' '; }
    }
    std::cout << '\n';
    double cases[][2] = {{40000,50000},{60000,50000},{-1,50000}};
    for (auto& c : cases) {
        try { std::cout << "approved " << settle(c[0],c[1]) << '\n'; }
        catch (const ClaimError& e) { std::cout << "claim rejected: " << e.what() << '\n'; }
        catch (const std::exception& e) { std::cout << "error: " << e.what() << '\n'; }
    }
    try {
        Tracked t;
        std::vector<int> v;
        v.reserve(v.max_size()); // may throw length_error or bad_alloc depending on implementation
    } catch (const std::exception& e) {
        std::cout << "allocation request failed safely: " << e.what() << '\n';
    } catch (...) { std::cout << "unknown failure\n"; }
}
