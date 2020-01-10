1116. Print Zero Even Odd
Medium

107

66

Add to List

Share
Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the threads is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.

 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"

class ZeroEvenOdd {
private:
    int n;
    int count;
    bool isZero;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        count=1;
        isZero=true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (1) {            
            while (count<=n && !isZero) cv.wait(lock);
            if (count>n) break;
            printNumber(0);
            isZero=false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (1) {            
            while (count<=n && (isZero || count%2==1)) cv.wait(lock);
            if (count>n) break;
            printNumber(count);
            isZero=true;
            count++;
            cv.notify_all();
        }        
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (1) {            
            while (count<=n && (isZero || count%2==0)) cv.wait(lock);
            if (count>n) break;
            printNumber(count);
            isZero=true;
            count++;
            cv.notify_all();
        }        
    }
};

