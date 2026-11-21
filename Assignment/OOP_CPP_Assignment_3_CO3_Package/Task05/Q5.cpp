#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;
    void normalize() { if(seconds<0) seconds=0; }
public:
    explicit Time(int h=0,int m=0,int s=0):seconds(h*3600+m*60+s){normalize();}
    Time& operator++() { ++seconds; return *this; }       // prefix
    Time operator++(int) { Time old=*this; ++seconds; return old; } // postfix
    bool operator==(const Time& t) const { return seconds==t.seconds; }
    bool operator<(const Time& t) const { return seconds<t.seconds; }
    friend ostream& operator<<(ostream& os,const Time& t) {
        int h=t.seconds/3600,m=(t.seconds/60)%60,s=t.seconds%60;
        return os<<h<<':'<<(m<10?"0":"")<<m<<':'<<(s<10?"0":"")<<s;
    }
};
class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> t):tracks(t){}
    string& operator[](int i) {
        if(i<0||i>=static_cast<int>(tracks.size())) throw out_of_range("playlist index");
        return tracks[i];
    }
    const string& operator[](int i) const {
        if(i<0||i>=static_cast<int>(tracks.size())) throw out_of_range("playlist index");
        return tracks[i];
    }
    int size() const { return static_cast<int>(tracks.size()); }
};
int main() {
    Time t(0,0,5);
    Time a=t++, b=++t;
    cout<<a<<' '<<b<<' '<<t<<'\n';
    Time roll(0,59,59); ++roll; cout<<"Rollover: "<<roll<<'\n';
    Playlist p={"Track One","Track Two"};
    cout<<p[0]<<'\n';
    try { cout<<p[p.size()]<<'\n'; }
    catch(const out_of_range& e){ cout<<"Range error: "<<e.what()<<'\n'; }
    const Playlist& cp=p; cout<<"Const access: "<<cp[1]<<'\n';
}
