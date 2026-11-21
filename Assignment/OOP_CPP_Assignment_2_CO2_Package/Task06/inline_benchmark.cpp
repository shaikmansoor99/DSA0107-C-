#include <iostream>
#include <chrono>
using namespace std;
volatile long long sinkValue = 0;

inline int inlineAdd(int a, int b) { return a + b; }
int normalAdd(int a, int b) { return a + b; }

int main() {
    const int loops = 20000000;
    long long sum = 0;
    auto start1 = chrono::steady_clock::now();
    for (int i = 0; i < loops; ++i) sum += inlineAdd(i & 7, i & 3);
    auto end1 = chrono::steady_clock::now();
    sinkValue = sum;

    sum = 0;
    auto start2 = chrono::steady_clock::now();
    for (int i = 0; i < loops; ++i) sum += normalAdd(i & 7, i & 3);
    auto end2 = chrono::steady_clock::now();
    sinkValue = sum;

    cout << "inline_ms="
         << chrono::duration<double, milli>(end1 - start1).count() << '\n';
    cout << "normal_ms="
         << chrono::duration<double, milli>(end2 - start2).count() << '\n';
}
