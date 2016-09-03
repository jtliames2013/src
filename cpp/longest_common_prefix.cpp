14. Longest Common Prefix  QuestionEditorial Solution  My Submissions
Total Accepted: 114633 Total Submissions: 391271 Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.

Hide Company Tags Yelp
Hide Tags String

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
    string longestCommonPrefix(vector<string> &strs) {
    	int end = 0;
    	if (strs.empty()) return string("");

    	int i;
    	while (1)
    	{
    		if (end == strs[0].size()) break;

    		for (i = 1; i < strs.size(); i++)
    		{
    			if (end == strs[i].size() || strs[i][end] != strs[0][end])
    			{
    				break;
    			}
    		}

    		if (i == strs.size())
    		{
    			end++;
    		}
    		else
    		{
    			break;
    		}
    	}

    	if (end == 0) return string("");
    	else return strs[0].substr(0, end);
    }
};

int main()
{
	return 0;
}

