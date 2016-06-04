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
    vector<int> plusOne(vector<int> &digits) {
    	int i;
    	for (i = digits.size() - 1; i >= 0; i--)
    	{
    		if (digits[i] == 9)
    		{
    			digits[i] = 0;
    		}
    		else
    		{
    			digits[i]++;
    			break;
    		}
    	}

    	if (i == -1 && digits[0] == 0)
    	{
    		digits.insert(digits.begin(), 1);
    	}

    	return digits;
    }
};

int main()
{
	return 0;
}

