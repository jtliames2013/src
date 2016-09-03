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
	 bool checkWordsInString(string& s, int index, map<string, int>& wordCount, int wordSize, int numWords) {
		 map<string, int> wordFound;
		 if (index+numWords*wordSize>s.size()) return false;

		 for (int i=index, j=0; j<numWords; i+=wordSize, j++) {
			 string word = s.substr(i, wordSize);
			 if (wordCount.find(word) == wordCount.end()) return false;
			 wordFound[word]++;
			 if (wordFound[word] > wordCount[word]) return false;
		 }

		 return true;
	 }

     vector<int> findSubstring(string s, vector<string>& words) {
    	 vector<int> res;
    	 map<string, int> wordCount;
    	 int wordSize=words[0].size();
    	 for (int i=0; i<words.size(); i++) {
    		 wordCount[words[i]]++;
    	 }

    	 for (int i=0; i<s.size(); i++) {
    		 if (checkWordsInString(s, i, wordCount, wordSize, words.size())) {
    			 res.push_back(i);
    		 }
    	 }

    	 return res;
     }
 };

int main()
{
	return 0;
}

