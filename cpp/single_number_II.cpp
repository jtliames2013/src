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
    	vector<int> count(32, 0);

    	for (int i = 0; i < 32; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			count[i] += ((0x1 << i) & A[j]) != 0 ? 1 : 0;
    		}
    	}

    	int res = 0;
    	for (int i = 0; i < 32; i++)
    	{
    		if (count[i] % 3 != 0)
    		{
    			res |= (0x1 << i);
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

