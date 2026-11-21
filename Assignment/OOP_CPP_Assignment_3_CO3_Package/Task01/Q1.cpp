#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    string author;
    int copies;
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Donated copy", 1) {}
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c < 0 ? 0 : c) {
        if (c < 0) throw invalid_argument("copies cannot be negative");
    }
    void print() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};

struct ExplicitDemo {
    explicit ExplicitDemo(int) {}
};

int main() {
    Book empty;
    Book donated("The Alchemist");
    Book full("1984", "George Orwell", 5);
    empty.print(); donated.print(); full.print();

    try {
        Book invalid("Bad record", "Nobody", -2);
        invalid.print();
    } catch (const invalid_argument& e) {
        cout << "Rejected: " << e.what() << '\n';
    }

    // Explicit constructor permits direct construction:
    ExplicitDemo direct(5);
    (void)direct;
    // Copy-initialisation ExplicitDemo x = 5; is intentionally not compiled:
    // it is rejected because the converting constructor is explicit.
}
