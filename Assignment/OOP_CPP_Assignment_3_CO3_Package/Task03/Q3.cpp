#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;

class Event {
    int rows, seatsPerRow;
    bool** seats;
    int booked;
public:
    Event(int r,int s) : rows(r), seatsPerRow(s), seats(nullptr), booked(0) {
        if (r < 0 || s < 0) throw invalid_argument("negative dimensions");
        if (rows == 0 || seatsPerRow == 0) return;
        seats = new bool*[rows]{};
        try {
            for(int i=0;i<rows;++i) seats[i]=new bool[seatsPerRow]{false};
        } catch (...) {
            for(int i=0;i<rows;++i) delete[] seats[i];
            delete[] seats; seats=nullptr; throw;
        }
        cout << "Created " << rows << "x" << seatsPerRow << '\n';
    }
    Event(const Event&)=delete;
    Event& operator=(const Event&)=delete;
    bool book(int r,int s) {
        if(!seats || r<0||r>=rows||s<0||s>=seatsPerRow||seats[r][s]) return false;
        seats[r][s]=true; ++booked; return true;
    }
    bool cancel(int r,int s) {
        if(!seats || r<0||r>=rows||s<0||s>=seatsPerRow||!seats[r][s]) return false;
        seats[r][s]=false; --booked; return true;
    }
    ~Event() {
        if(seats) { for(int i=0;i<rows;++i) delete[] seats[i]; delete[] seats; }
        cout << "Closed event; booked seats=" << booked << '\n';
    }
};
int main() {
    Event stackEvent(2,3);
    stackEvent.book(0,1); stackEvent.book(1,2); stackEvent.cancel(0,1);
    { Event blockEvent(1,2); blockEvent.book(0,0); }
    Event* heapEvent=new Event(1,1); heapEvent->book(0,0); delete heapEvent;
    Event zeroRows(0,5);
}
