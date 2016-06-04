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

int main()
{
	return 0;
}


