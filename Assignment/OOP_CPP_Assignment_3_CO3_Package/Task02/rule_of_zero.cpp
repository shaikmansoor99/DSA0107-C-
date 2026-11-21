#include <string>
#include <vector>
class PrescriptionSafe {
    std::vector<std::string> medicines;
public:
    explicit PrescriptionSafe(int n) : medicines(n > 0 ? n : 0) {}
};
// Compiler-generated copy operations correctly copy vector contents (Rule of Zero).
int main(){ PrescriptionSafe a(3); PrescriptionSafe b=a; b=a; }
