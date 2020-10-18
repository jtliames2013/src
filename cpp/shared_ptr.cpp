#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <mutex>
#include <condition_variable>
#include <cctype>
#include <functional>
#include <exception>
#include <stdexcept>
#include <thread>
#include <climits>
#include <float.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <time.h> 

using namespace std;

class Counter {
public:
    Counter(): counter(0) {}
    
    ~Counter() {}
    
    unsigned int get() {
        return counter;
    }

    void operator++(int) {
        counter++;
    }

    void operator--(int) {
        counter--;
    }

    friend ostream& operator<<(ostream& os, const Counter& counter) {
        os << "Counter is: " << counter.counter << endl;
    }
private:
    unsigned int counter;
};

template<class T>
class SharedPtr {
    T* ptr;
    Counter* counter;
public:
    explicit SharedPtr(T* p=NULL) {
        ptr=p;
        counter=new Counter();
        if (p) (*counter)++;
    }


    ~SharedPtr() {
        (*counter)--;
        if (counter->get()==0) {
            delete ptr;
            delete counter;
        }
    }

    SharedPtr(SharedPtr<T>& sp) {
        ptr=sp.ptr;
        counter=sp.counter;
        (*counter)++;
    }

    SharedPtr& operator=(const SharedPtr& r) {
        ptr=r.ptr;
        counter=r.counter;
        (*counter)++;
        return *this;
    }

    T* get() {
        return ptr;
    }

    unsigned int use_count() {
        return counter->get();
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    friend ostream& operator<<(ostream& os, SharedPtr<T>& sp) {
        os << "Pointer is: " << sp.get() << endl;
        cout << *(sp.counter) << endl;
    }
};


int main(int argc, char** argv) {
    SharedPtr<int> sp1(new int(10));
    *sp1=20;
    cout << "shared pointer 1" << endl;
    cout << sp1 << endl;
    
    {
        SharedPtr<int> sp2=sp1;
        cout << "shared pointer 1 and 2" << endl;
        cout << sp1 << endl;
        cout << sp2 << endl;
    }

    cout << "shared pointer 1" << endl;
    cout << sp1 << endl;

    return 0;    
}

