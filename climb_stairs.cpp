#include <stdio.h>
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

class Solution {
public:
    int climbStairs(int n) {
    	if (n <= 1) return 1;

    	int a = 1, b = 1, c;
    	for (int i = 2; i <= n; i++)
    	{
    		c = a + b;
    		a = b;
    		b = c;
    	}

    	return c;
    }
};

int main()
{
	return 0;
}

