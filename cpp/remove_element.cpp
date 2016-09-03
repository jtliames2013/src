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
    int removeElement(int A[], int n, int elem) {
    	int end = 0;
    	for (int i = 0; i < n; i++)
    	{
    		if (A[i] != elem)
    		{
    			A[end] = A[i];
    			end++;
    		}
    	}

    	return end;
    }
};

2. when removed element is rare.

class Solution {

public:

    int removeElement(vector<int>& nums, int val) {

        int start=0, end=nums.size()-1;

        

        while (start<=end) {

            if (nums[start]==val) {

                nums[start]=nums[end];

                end--;

            } else {

                start++;

            }

        }

        

        return end+1;

    }

};

int main()
{
	return 0;
}

