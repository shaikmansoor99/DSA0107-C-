#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

class ShiftHistory {
    vector<int> data;
    int capacity;
public:
    explicit ShiftHistory(int k) : capacity(k) {}
    void add(int value) {
        if ((int)data.size() < capacity) data.push_back(value);
        else {
            for (int i = 1; i < capacity; ++i) data[i - 1] = data[i];
            data[capacity - 1] = value;
        }
    }
    long long checksum() const {
        long long s = 0;
        for (int x : data) s += x;
        return s;
    }
};

class CircularHistory {
    vector<int> data;
    int capacity, count = 0, next = 0;
public:
    explicit CircularHistory(int k) : data(k), capacity(k) {}
    void add(int value) {
        data[next] = value;
        next = (next + 1) % capacity;
        if (count < capacity) ++count;
    }
    long long checksum() const {
        long long s = 0;
        for (int i = 0; i < count; ++i) s += data[i];
        return s;
    }
};

int main() {
    const int k = 50;
    const int operations = 2000000;
    ShiftHistory shifted(k);
    CircularHistory circular(k);

    auto s1 = chrono::steady_clock::now();
    for (int i = 0; i < operations; ++i) shifted.add(i);
    auto e1 = chrono::steady_clock::now();

    auto s2 = chrono::steady_clock::now();
    for (int i = 0; i < operations; ++i) circular.add(i);
    auto e2 = chrono::steady_clock::now();

    cout << "Shift checksum: " << shifted.checksum() << '\n';
    cout << "Circular checksum: " << circular.checksum() << '\n';
    cout << "Shift add total ms: "
         << chrono::duration<double, milli>(e1 - s1).count() << '\n';
    cout << "Circular add total ms: "
         << chrono::duration<double, milli>(e2 - s2).count() << '\n';
}
