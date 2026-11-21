#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
bool readInt(const std::string& prompt, int& value) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) return true;
        if (std::cin.eof()) return false;
        std::cout << "Invalid numeric input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
int main() {
    int hour=0;
    if (!readInt("Enter hour (0-23): ",hour)) return 1;
    if (hour<0 || hour>23) { std::cout << "Hour out of range\n"; return 1; }
    const bool peak=(hour>=8 && hour<10)||(hour>=17 && hour<20);
    const long long farePaise=peak?3600:3000;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Peak: " << std::boolalpha << peak << '\n';
    std::cout << "Fare: Rs " << static_cast<double>(farePaise)/100.0 << '\n';
}