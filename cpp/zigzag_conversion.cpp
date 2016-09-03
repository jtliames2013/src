NOTE:
abcdefghijk  n=4

a g
bfh
ceik
d j


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
    string convert(string s, int nRows) {
    	if (nRows == 0) return s;
    	string res;
    	int l = s.size();
    	int m = 0;
		if (nRows >= 3)
		{
			m = nRows - 2;
		}

    	for (int i = 0; i < nRows; i++)
    	{
    		int j = i;
    		int k = 0;
    		if (i > 0 && i < nRows - 1)
    		{
    			k = nRows + nRows - 2 - i;
    		}

    		while (j < l)
    		{
    			res.push_back(s[j]);

    			if (i > 0 && i < nRows - 1)
    			{
       				if (k < l)
    				{
    					res.push_back(s[k]);
    				}
    			}

    			j += nRows + m;
    			k += nRows + m;
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

