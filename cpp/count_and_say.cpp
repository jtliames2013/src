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
    string countAndSay(int n) {
    	string prev, curr;

    	if (n == 0) return curr;
    	if (n == 1)
    	{
    		curr.push_back('1');
    		return curr;
    	}

    	prev.push_back('1');
    	int cnt;
    	for (int i = 1; i < n; i++)
    	{
    		curr.clear();
    		cnt = 0;
    		char start = prev[0];
    		for (int j = 0; j < prev.size(); j++)
    		{
    			if (prev[j] == start) cnt++;
    			else
    			{
    				curr.push_back(cnt + '0');
    				curr.push_back(start);
    				start = prev[j];
    				cnt = 1;
    			}
    		}

    		curr.push_back(cnt + '0');
    		curr.push_back(start);
    		prev = curr;
    	}

    	return curr;
    }
};

int main()
{
	return 0;
}

