#include <iostream>
#include <string>
using namespace std;

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    string name;

public:
    explicit BusTicket(const string& n) : seat(0), name(n) {
        if (issued < CAPACITY) {
            ++issued;
            seat = issued;
        }
    }

    static int count() { return issued; }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat) : string("Waiting")) << '\n';
    }
};

int BusTicket::issued = 0;

class Token {
    static int next;
    int id;
public:
    Token() { id = ++next; }
    int get() const { return id; }
    static int issued() { return next - 100; }
};
int Token::next = 100;

void createMoreTickets() {
    BusTicket extra1("Esha");
    BusTicket extra2("Farhan");
    extra1.print();
    extra2.print();
}

int main() {
    Token counter[3];
    Token extra;
    cout << counter[0].get() << ' ' << counter[2].get() << ' '
         << extra.get() << ' ' << Token::issued() << '\n';

    BusTicket trip[4] = {BusTicket("Asha"), BusTicket("Bala"),
                         BusTicket("Chitra"), BusTicket("Dev")};
    for (const BusTicket& t : trip) t.print();
    cout << "Issued: " << BusTicket::count() << '\n';

    createMoreTickets();
    cout << "Issued after second function call: " << BusTicket::count() << '\n';
    createMoreTickets();
    cout << "Issued after another function call: " << BusTicket::count() << '\n';
}
