#include <iostream>
#include <string>
using namespace std;

class Address {
    string city; int pin;
public:
    Address(string c,int p):city(move(c)),pin(p){cout<<"Address+ ";}
    string str() const { return city+"-"+to_string(pin); }
    ~Address(){cout<<"Address- ";}
};
class Course {
    string title;
public:
    explicit Course(string t):title(move(t)){cout<<"Course+ ";}
    string get() const{return title;}
    ~Course(){cout<<"Course- ";}
};
class Person {
protected:
    string name; int age; Address home;
public:
    Person(string n,int a,string city,int pin)
        :name(move(n)),age(a),home(move(city),pin){cout<<"Person+ ";}
    virtual ~Person(){cout<<"Person- ";}
};
class Student : virtual public Person {
protected:
    long long regNo; Course course;
public:
    Student(string n,int a,long long r,string city,int pin,string c)
        :Person(move(n),a,move(city),pin),regNo(r),course(move(c)){cout<<"Student+ ";}
    ~Student() override {cout<<"Student- ";}
    void print() const {cout<<regNo<<' '<<name<<" ("<<age<<") "<<home.str()<<" "<<course.get()<<'\n';}
};
class Staff : virtual public Person {
protected: string department;
public:
    Staff(string n,int a,string city,int pin,string d)
        :Person(move(n),a,move(city),pin),department(move(d)){cout<<"Staff+ ";}
    ~Staff() override {cout<<"Staff- ";}
};
class TA : public Student, public Staff {
public:
    TA(string n,int a,long long r,string city,int pin,string c,string d)
        :Person(n,a,city,pin),Student(n,a,r,city,pin,c),Staff(n,a,city,pin,d){cout<<"TA+ ";}
    ~TA() override {cout<<"TA- ";}
};
int main(){
    cout<<"Student lifetime: ";
    { Student s("Kavya",19,192311001,"Salem",636001,"C++"); s.print(); }
    cout<<"\nTA lifetime: ";
    { TA t("Arun",21,192311002,"Chennai",600001,"OOP","CSE"); }
    cout<<'\n';
}
