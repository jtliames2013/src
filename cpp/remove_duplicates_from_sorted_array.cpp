26. Remove Duplicates from Sorted Array  QuestionEditorial Solution  My Submissions
Total Accepted: 148550 Total Submissions: 432614 Difficulty: Easy
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Hide Company Tags Microsoft Bloomberg Facebook
Hide Tags Array Two Pointers
Hide Similar Problems (E) Remove Element

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

