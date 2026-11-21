#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;
public:
    Person(string n,int i,string p):name(move(n)),id(i),phone(move(p)){}
    virtual ~Person()=default;
    string getName() const { return name; }
};
class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n,int i,string p,string pr,double c)
        :Person(move(n),i,move(p)),programme(move(pr)),cgpa(c){}
};
class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n,int i,string p,string d,double s)
        :Person(move(n),i,move(p)),department(move(d)),salary(s){}
};
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n,int i,string p,string pr,double c,string d,double s)
        :Person(n,i,p),Student(n,i,p,pr,c),Staff(n,i,p,d,s){}
    void print() const {
        cout << name << " | " << id << " | " << programme << " | "
             << department << " | " << cgpa << " | " << salary << '\n';
    }
};
class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n,int i,string p,string pr,double c,double f)
        :Person(move(n),i,move(p)),Student(n,i,p,move(pr),c),fellowship(f){}
    void print() const { cout<<name<<" fellowship=Rs "<<fellowship<<'\n'; }
};

struct AccessDemo {
public: int pub=1;
protected: int prot=2;
private: int priv=3;
};
class PublicStudent : public AccessDemo {};
class ProtectedStudent : protected AccessDemo {};
class PrivateStudent : private AccessDemo {};

struct PersonOnce { PersonOnce(){cout<<"Person ";} };
struct StudentOnce : virtual PersonOnce { StudentOnce(){cout<<"Student ";} };
struct StaffOnce : virtual PersonOnce { StaffOnce(){cout<<"Staff ";} };
struct TAOnce : StudentOnce,StaffOnce { TAOnce(){cout<<"TA ";} };

int main() {
    TAOnce ta; cout<<'\n';
    TeachingAssistant t("Mira",12,"99999","BTech AI",8.6,"CSE",45000);
    t.print();
    ResearchScholar r("Dev",13,"88888","PhD",9.1,25000);
    r.print();
    cout << "sizeof(Person)="<<sizeof(Person)<<" sizeof(TA)="<<sizeof(TeachingAssistant)<<'\n';
}
