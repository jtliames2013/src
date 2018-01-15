#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <thread>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <bitset>
#include <chrono>
#include <ctime>
#include <thread>
#include <string.h>

using namespace std;
using namespace std::chrono;

struct BoundedBuffer {
    int* buffer;
    int capacity;
    int head;
    int tail;
    int count;

    std::mutex mx;

    std::condition_variable cv_full;
    std::condition_variable cv_empty;

    BoundedBuffer(int capacity) : capacity(capacity), head(0), tail(0), count(0) {
        buffer = new int[capacity];
    }

    ~BoundedBuffer(){
        delete[] buffer;
    }

    void produce(int data){
        std::unique_lock<std::mutex> lock(mx);

        while (count==capacity) {
        	cv_full.wait(lock, [this](){return count < capacity; });
        }

        buffer[tail] = data;
        tail = (tail + 1) % capacity;
        count++;

        cv_empty.notify_all();
        lock.unlock();
    }

    int consume(){
        std::unique_lock<std::mutex> lock(mx);

        while (count==0) {
        	cv_empty.wait(lock, [this](){return count > 0; });
        }

        int result = buffer[head];
        head = (head + 1) % capacity;
        count--;

        cv_full.notify_all();
        lock.unlock();

        return result;
    }
};

void consumer(int id, BoundedBuffer& buffer){
    for(int i = 0; i < 10; ++i){
        int value = buffer.consume();
        std::cout << "Consumer " << id << " consumed " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void producer(int id, BoundedBuffer& buffer){
    for(int i = 0; i < 10; ++i){
        buffer.produce(i);
        std::cout << "Producer " << id << " produced " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(){
    BoundedBuffer buffer(10);

    std::thread c1(consumer, 0, std::ref(buffer));
    std::thread c2(consumer, 1, std::ref(buffer));
    std::thread c3(consumer, 2, std::ref(buffer));
    std::thread p1(producer, 0, std::ref(buffer));
    std::thread p2(producer, 1, std::ref(buffer));
    std::thread p3(producer, 2, std::ref(buffer));

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();
    p3.join();

    return 0;
}

