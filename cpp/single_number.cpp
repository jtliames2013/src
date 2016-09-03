136. Single Number  QuestionEditorial Solution  My Submissions
Total Accepted: 149841 Total Submissions: 290736 Difficulty: Easy
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Hide Tags Hash Table Bit Manipulation
Hide Similar Problems (M) Single Number II (M) Single Number III (M) Missing Number (H) Find the Duplicate Number (E) Find the Difference

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

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
    int singleNumber(int A[], int n) {
    	int res = A[0];

    	for (int i = 1; i < n; i++)
    	{
    		res = res ^ A[i];
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

