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

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0)
        {
        	neg = true;
        	x = 0 - x;
        }

        int n = 0;
        while (x > 0)
        {
        	n *= 10;
        	n += x % 10;
        	x /= 10;
        }

        if (neg) n = 0 - n;
        return n;
    }
};

int main()
{
	return 0;
}

