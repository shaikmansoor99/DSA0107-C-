#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

const int& highestMarkReadOnly(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

int highestMarkCopy(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

int highestMarkIndex(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return best;
}

int* highestMarkPointer(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return &marks[best];
}

// Deliberately unsafe example for compiler-warning investigation.
// Do NOT call this function: its returned reference would dangle.
int& danglingReference() {
    int local = 99;
    return local;
}

int main() {
    int marks[] = {78, 91, 84, 88};
    int n = 4;

    cout << "Highest before moderation: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "Highest after moderation: " << highestMark(marks, n) << '\n';

    const int& readOnly = highestMarkReadOnly(marks, n);
    cout << "Read-only highest: " << readOnly << '\n';
    cout << "Copy of highest: " << highestMarkCopy(marks, n) << '\n';

    int index = highestMarkIndex(marks, n);
    int* ptr = highestMarkPointer(marks, n);
    cout << "Index: " << index << ", value: " << marks[index] << '\n';
    *ptr += 1;
    cout << "After pointer update: " << marks[index] << '\n';

    vector<int> growing = {10, 20, 30};
    growing.reserve(3);
    int* oldAddress = &growing[2];
    growing.push_back(40); // capacity may grow; oldAddress may now be invalid.
    cout << "Vector size after growth: " << growing.size() << '\n';
    (void)oldAddress; // Do not dereference a possibly invalidated pointer.
}
