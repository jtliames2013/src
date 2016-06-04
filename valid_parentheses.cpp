nclude <stdio.h>
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
    bool isValid(string s) {
    	vector<char> res;

    	for (int i = 0; i < s.size(); i++)
    	{
    		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
    		{
    			res.push_back(s[i]);
    		}
    		else
    		{
    			if (!res.empty() &&
    				((s[i] == '}' && res.back() == '{') ||
    				 (s[i] == ')' && res.back() == '(') ||
    				 (s[i] == ']' && res.back() == '[')))
    			{
    				res.pop_back();
    			}
    			else
    			{
    				return false;
    			}
    		}
    	}

    	if (res.empty()) return true;
    	else return false;
    }
};

int main()
{
	return 0;
}

