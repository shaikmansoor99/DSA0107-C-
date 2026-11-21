#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Text {
    size_t len;
    char* data;
public:
    explicit Text(const char* s="") : len(strlen(s)), data(new char[len+1]) {
        memcpy(data,s,len+1);
    }
    Text(const Text& other):len(other.len),data(new char[len+1]) {
        cout<<"[copy] ";
        memcpy(data,other.data,len+1);
    }
    Text& operator=(const Text& other) {
        if(this==&other) return *this;
        char* fresh=new char[other.len+1];
        memcpy(fresh,other.data,other.len+1);
        delete[] data; data=fresh; len=other.len;
        return *this;
    }
    ~Text(){delete[] data;}
    Text operator+(const Text& rhs) const {
        size_t n=len+rhs.len;
        char* temp=new char[n+1];
        memcpy(temp,data,len);
        memcpy(temp+len,rhs.data,rhs.len+1);
        Text result(temp);
        delete[] temp;
        return result;
    }
    bool operator==(const Text& rhs) const {return strcmp(data,rhs.data)==0;}
    bool operator!=(const Text& rhs) const {return !(*this==rhs);}
    friend ostream& operator<<(ostream& os,const Text& t){return os<<t.data;}
};
int main(){
    Text a("Hello"),b(" "),c("World");
    Text joined=a+b+c;
    cout<<'\n'<<joined<<'\n';
    Text empty("");
    cout<<"Empty: ["<<empty<<"]\n";
    Text longText("A longer SMS message for testing");
    Text copy=longText;
    copy=copy;
    cout<<"Independent copy: "<<copy<<'\n';
    cout<<boolalpha<<(a!=c)<<' '<<(a==a)<<'\n';
}
