#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class Solution {
 public:
	 void getWordBreak(string& s, unordered_set<string>& wordDict, int start, vector<string>& res, vector<string>& words, vector<bool>& canBreak) {
		 if (start==s.size()) {
			 string result;
			 for (int i=0; i<words.size(); i++) {
				 result.append(words[i]);
				 if (i<words.size()-1) {
					 result.append(" ");
				 }
			 }

			 res.push_back(result);
			 return;
		 }

		 for (int i=start; i<s.size(); i++) {
			 string w=s.substr(start, i-start+1);
			 if (wordDict.find(w)!=wordDict.end() && canBreak[i+1]==true) {
				 words.push_back(w);
				 int len=res.size();
				 getWordBreak(s, wordDict, i+1, res, words, canBreak);
				 if (res.size()==len) {
					 canBreak[i+1]=false;
				 }

				 words.pop_back();
			 }
		 }
	 }

     vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	 vector<string> res;
    	 vector<string> words;
    	 vector<bool> canBreak(s.size()+1, true);

    	 getWordBreak(s, wordDict, 0, res, words, canBreak);

    	 return res;
     }
 };

int main()
{
	return 0;
}

