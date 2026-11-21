#include <iostream>
struct Person { Person(){std::cout<<"Person ";} };
struct Student : Person { Student(){std::cout<<"Student ";} };
struct Staff : Person { Staff(){std::cout<<"Staff ";} };
struct TA : Student,Staff { TA(){std::cout<<"TA ";} };
int main(){ TA t; std::cout<<'\n'; }
