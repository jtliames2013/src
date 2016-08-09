3. Longest Substring Without Repeating Characters  
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Hide Company Tags Amazon Adobe Bloomberg Yelp
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

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

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	map<char, int> pos;
    	int res=0;
    	int start=0;
    	for (int i=0; i<s.size(); i++) {
    		if (pos.find(s[i])!=pos.end()) {
    			if (res<i-start) res=i-start;
    			int newstart=pos[s[i]]+1;
    			for (int j=start; j<newstart; j++) {
    				pos.erase(s[j]);
    			}
    			pos.insert({s[i], i});
    			start=newstart;
    		} else {
    			pos.insert({s[i], i});
    		}
    	}

    	if (res<s.size()-start) res=s.size()-start;

    	return res;
    }
};

2.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> pos;
        int len=0;
        int start=0;
        for (int i=0; i<s.size(); i++) {
            auto iter=pos.find(s[i]);
            if (iter!=pos.end()) {
                len=max(len, i-start);
                for (int j=start; j<=iter->second; j++) {
                    pos.erase(s[j]);
                }
                start=iter->second+1;
            }
            
            pos[s[i]]=i;
        }
        len=max(len, (int)s.size()-start);
        
        return len;
    }
};

int main()
{
	return 0;
}


