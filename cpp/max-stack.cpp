716. Max Stack 
Average Rating: 3.60 (5 votes)
Nov. 25, 2017  |  2.4K views
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        v.push_front(x);
        m[x].push_back(v.begin());
    }

    int pop() {
        int x = v.front();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.pop_front();
        return x;
    }

    int top() {
        return v.front();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        int x = m.rbegin()->first;
        auto iter = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(iter);
        return x;
    }

private:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
};

