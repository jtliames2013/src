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
    int removeDuplicates(int A[], int n) {
    	int end = 1;
    	if (n == 0) return 0;

    	for (int i = 1; i < n; i++)
    	{
    		if (A[i - 1] != A[i])
    		{
    			A[end] = A[i];
    			end++;
    		}
    	}

    	return end;
    }
};

int main()
{
	return 0;
}

