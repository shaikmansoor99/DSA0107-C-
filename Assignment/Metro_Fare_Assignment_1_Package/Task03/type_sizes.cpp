#include <climits>
#include <iostream>
int main() {
 std::cout << "bool=" << sizeof(bool) << " char=" << sizeof(char)
           << " int=" << sizeof(int) << " unsigned=" << sizeof(unsigned)
           << " long long=" << sizeof(long long) << " float=" << sizeof(float)
           << " double=" << sizeof(double) << '\n';
 std::cout << "INT_MAX=" << INT_MAX << " UINT_MAX=" << UINT_MAX
           << " LLONG_MAX=" << LLONG_MAX << '\n';
}