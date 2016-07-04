139. Word Break 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Hide Company Tags Google Uber Facebook Amazon Yahoo Bloomberg Pocket Gems

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

1. use iteration. Check each substring up to i can break. For each i, check each substring up to j can break and the rest is a word.
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	if (s.empty()) return true;

    	int len = s.size();
    	vector<bool> res(len, false);

    	for (int i = 0; i < len; i++)
    	{
    		bool r = false;
    		for (int j = -1; j < i; j++)
    		{
    			if (j > -1)
    			{
    				if (res[j] == true && dict.find(s.substr(j+1, i-j)) != dict.end())
    				{
    					r = true;
					break;
    				}
    			}
    			else
    			{
    				if (dict.find(s.substr(0, i+1)) != dict.end())
    				{
    					r = true;
					break;
    				}
    			}
    		}
    		res[i] = r;
    	}

    	return res[len-1];
    }
};

2. use recursion and optimize using canBreak array. 
class Solution {

public:

    bool findBreak(string& s, unordered_set<string>& dict, int start, vector<bool>& canBreak) {

        if (start>=s.size()) return true;

        

        for (int i=start; i<s.size(); i++) {

            string str=s.substr(start, i-start+1);

            if (dict.find(str)!=dict.end() && canBreak[i+1]==true) {

                if (findBreak(s, dict, i+1, canBreak)==true) {

                    return true;

                } else {

                    canBreak[i+1]=false;

                }

            }

        }

        return false;

    }

    

    bool wordBreak(string s, unordered_set<string>& wordDict) {

        vector<bool> canBreak(s.size()+1, true);

        return findBreak(s, wordDict, 0, canBreak);

    }

};


int main()
{
	return 0;
}

