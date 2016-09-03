20. Valid Parentheses  QuestionEditorial Solution  My Submissions
Total Accepted: 126656 Total Submissions: 413593 Difficulty: Easy
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Hide Company Tags Google Airbnb Facebook Twitter Zenefits Amazon Microsoft Bloomberg
Hide Tags Stack String
Hide Similar Problems (M) Generate Parentheses (H) Longest Valid Parentheses (H) Remove Invalid Parentheses

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

