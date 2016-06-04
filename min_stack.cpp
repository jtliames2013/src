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

