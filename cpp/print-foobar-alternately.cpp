1115. Print FooBar Alternately
Medium

177

13

Add to List

Share
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.

class FooBar {
private:
    int n;
    int count;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        count=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while (count%2==1) cv.wait(lock);
            count++;
            
	    // printFoo() outputs "foo". Do not change or remove this line.
	    printFoo();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while (count%2==0) cv.wait(lock);
            count++;
            
	    // printBar() outputs "bar". Do not change or remove this line.
	    printBar();
            cv.notify_all();
        }
    }
};

