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
    int findMin(vector<int> &num) {
    	if (num.empty()) return 0;

    	int l = 0, r = num.size() - 1;
    	int m;

    	while (l < r)
    	{
    		if (l == r - 1) return num[l] < num[r] ? num[l] : num[r];
    		m = (l + r) / 2;
    		if (num[m] > num[l] && num[m] > num[r])
    		{
    			l = m;
    		}
    		else
    		{
    			r = m;
    		}
    	}

    	return num[l];
    }
};

int main()
{
	return 0;
}

