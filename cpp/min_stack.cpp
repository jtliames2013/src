155. Min Stack 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

用另一个stack<int> trackMin来记录min值的变化，trackMin.top()表示当前最小值。
当有新的xi<=trackMin.top()被压入时，将xi压入trackMin变为新的当前最小值。
当xi==trackMin.top()时被pop出时，trackMin也同时pop。

1. two stacks
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if (min.empty() || x<=min.back()) min.push_back(x);
    }
    
    void pop() {
        if (!data.empty()) {
            int t=data.back();
            data.pop_back();
            if (min.back()==t) min.pop_back();
        }
    }
    
    int top() {
        if (data.empty()) return 0; 
        return data.back();
    }
    
    int getMin() {
        if (min.empty()) return 0;
        return min.back();
    }
private:
    vector<int> data;
    vector<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

2. one stack
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal=0;
    }
    
    void push(int x) {
        if (data.empty()) {
            data.push_back(0);
            minVal=x;
        } else {
            data.push_back(x-minVal);
            if (x<minVal) minVal=x;
        }
    }
    
    void pop() {
        if (data.empty()) return;
        if (data.back()<0) minVal-=data.back();
        data.pop_back();
    }
    
    int top() {
        if (data.empty()) return -1;        
        if (data.back()>=0) return data.back()+minVal;
        else return minVal;
    }
    
    int getMin() {
        return minVal;
    }
private:
    vector<long> data;
    long minVal;
};

