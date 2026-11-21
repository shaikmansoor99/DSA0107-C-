#include <string>
struct NoDefault {
    explicit NoDefault(int value) : value(value) {}
    int value;
};
// NoDefault items[2]; // compile-time error: no default constructor
struct OrderWarning {
    int first;
    int second;
    OrderWarning() : second(2), first(second) {}
};
// Compile with -Wreorder to observe declaration-order warning.
// first is initialized before second regardless of initializer-list order.
int main() { OrderWarning x; return x.first; }
