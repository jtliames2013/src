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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class MinStack {
public:
    void push(int x) {
    	v.push_back(x);
	// note <= here since duplicate is pushed
    	if (min.empty() || x <= min.back())
    	{
    		min.push_back(x);
    	}
    }

    void pop() {
    	if (!v.empty())
    	{
    		if (min.back() == v.back()) min.pop_back();
    		v.pop_back();
    	}
    }

    int top() {
    	if (!v.empty())
    	{
    		int res = v.back();
    		return res;
    	}
    	else
    	{
    		return 0;
    	}
    }

    int getMin() {
    	if (!min.empty())
    	{
    		int res = min.back();
    		return res;
    	}
    	else
    	{
    		return 0;
    	}
    }

    deque<int> v;
    deque<int> min;
};

int main()
{
	return 0;
}

