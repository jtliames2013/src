346. Moving Average from Data Stream
Easy

398

46

Favorite

Share
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

Amazon
|
4

Microsoft
|
2

Google
|
2

Uber
|
2

1. deque
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
        sum=0;
    }
    
    double next(int val) {
        sum+=val;
        dq.push_back(val);
        if (dq.size()>size) {
            sum-=dq.front();
            dq.pop_front();
        }
        return sum/dq.size();
    }
private:
    int size;
    double sum;
    deque<int> dq;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

2. circular array
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
        count=tail=sum=0;
        data.resize(size);
    }

    double next(int val) {
        if (count<size) count++;
        if (count==size) sum-=data[tail];
        sum+=val;
        data[tail]=val;
        tail=(tail+1)%size;
        return sum/count;
    }
private:
    int size;
    int count;
    int tail;
    double sum;
    vector<int> data;
};

