46. Moving Average from Data Stream 
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
Hide Company Tags Google
Hide Tags Design Queue

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n=size;
        sum=0;
    }
    
    double next(int val) {
        if (q.size()<n) {
            q.push(val);
            sum+=val;
        } else {
            int f=q.front();
            q.pop();
            q.push(val);
            sum+=val-f;
        }
        return sum/q.size();
    }
private:
    queue<int> q;
    int n;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
