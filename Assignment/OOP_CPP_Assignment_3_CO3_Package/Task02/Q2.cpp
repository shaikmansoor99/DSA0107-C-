#include <iostream>
#include <string>
#include <chrono>
#include <utility>
using namespace std;

class Prescription {
    int n;
    string* medicines;
public:
    explicit Prescription(int count) : n(count), medicines(new string[count > 0 ? count : 0]) {
        if (count < 0) throw invalid_argument("negative medicine count");
    }
    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n]) {
        cout << "[copy constructor] ";
        for (int i=0;i<n;++i) medicines[i]=other.medicines[i];
    }
    Prescription& operator=(const Prescription& other) {
        if (this == &other) return *this;
        string* fresh = new string[other.n];
        for (int i=0;i<other.n;++i) fresh[i]=other.medicines[i];
        delete[] medicines;
        medicines=fresh; n=other.n;
        return *this;
    }
    ~Prescription() { delete[] medicines; }
    void set(int i,const string& m) { if(i<0||i>=n) throw out_of_range("medicine index"); medicines[i]=m; }
    string get(int i) const { if(i<0||i>=n) throw out_of_range("medicine index"); return medicines[i]; }
    int size() const { return n; }
};
void byValue(Prescription p) { cout << "by value size " << p.size() << '\n'; }
void byConstReference(const Prescription& p) { cout << "by const reference size " << p.size() << '\n'; }

int main() {
    Prescription p(2); p.set(0,"Paracetamol"); p.set(1,"ORS");
    Prescription q=p; q.set(1,"Cetirizine");
    Prescription r(1); r=p; p.set(0,"Ibuprofen");
    cout << p.get(0)<<' '<<p.get(1)<<" | "<<q.get(0)<<' '<<q.get(1)
         <<" | "<<r.get(0)<<' '<<r.get(1)<<'\n';
    r=r; // self-assignment test
    byValue(p);
    byConstReference(p);
}
