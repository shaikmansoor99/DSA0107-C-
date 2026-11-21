#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balancePaise;
    struct Transaction {
        string description;
        long long amountPaise;
    };
    Transaction transactions[10];
    int count;
    int next; // next position to overwrite when full

    void record(const string& description, long long amountPaise) {
        transactions[next] = {description, amountPaise};
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }

public:
    SavingsAccount(const string& number, long long openingBalance)
        : accountNumber(number), balancePaise(openingBalance), count(0), next(0) {}

    void deposit(long long amountPaise) {
        if (amountPaise <= 0) return;
        balancePaise += amountPaise;
        record("Deposit", amountPaise);
    }

    bool withdraw(long long amountPaise) {
        if (amountPaise <= 0 || amountPaise > balancePaise) return false;
        balancePaise -= amountPaise;
        record("Withdrawal", -amountPaise);
        return true;
    }

    void miniStatement() const; // defined outside the class
    long long balance() const { return balancePaise; } // defined inside
};

void SavingsAccount::miniStatement() const {
    cout << "Mini-statement for " << accountNumber << '\n';
    int start = (count == 10) ? next : 0;
    for (int i = 0; i < count; ++i) {
        int index = (start + i) % 10;
        cout << transactions[index].description << ": "
             << (transactions[index].amountPaise < 0 ? "-" : "+")
             << (transactions[index].amountPaise < 0
                 ? -transactions[index].amountPaise : transactions[index].amountPaise)
             << " paise\n";
    }
    cout << "Balance: " << balancePaise << " paise\n";
}

int main() {
    SavingsAccount account("SA1024", 100000);
    account.deposit(5000);
    account.withdraw(12000);
    for (int i = 1; i <= 10; ++i) account.deposit(i * 100);
    account.miniStatement();
}
