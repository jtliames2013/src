49. Group Anagrams  QuestionEditorial Solution  My Submissions
Total Accepted: 86398 Total Submissions: 295781 Difficulty: Medium
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

Hide Company Tags Amazon Bloomberg Uber Facebook Yelp
Hide Tags Hash Table String
Hide Similar Problems (E) Valid Anagram (E) Group Shifted Strings

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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string> > res;
    	map<string, vector<int> > m;
    	for (int i=0; i<strs.size(); i++) {
    		string str=strs[i];
    		std::sort(str.begin(), str.end());
    		m[str].push_back(i);
    	}

    	map<string, vector<int> >::iterator Iter;
    	for (Iter=m.begin(); Iter!=m.end(); Iter++) {
    		vector<string> v;
    		for (int i=0; i<Iter->second.size(); i++) {
    			v.push_back(strs[Iter->second[i]]);
    		}
    		std::sort(v.begin(), v.end());
    		res.push_back(v);
    	}

    	return res;
    }
};

2.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (auto str:strs) {
            string key=str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        
        for (auto iter:m) {
            res.push_back(iter.second);    
        }
        
        return res;
    }
};

int main()
{
	return 0;
}


