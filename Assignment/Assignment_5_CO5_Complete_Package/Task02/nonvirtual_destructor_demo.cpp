#include <iostream>
struct Base { ~Base() { std::cout << "~Base "; } virtual void f() {} };
struct Derived : Base { ~Derived() { std::cout << "~Derived "; } };
int main() { Base* p = new Derived; delete p; std::cout << '\n'; }
