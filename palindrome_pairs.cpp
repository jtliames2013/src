use set to avoid the case where two words are revert of each other.

利用字典wmap保存单词 -> 下标的键值对

遍历单词列表words，记当前单词为word，下标为idx：

1). 若当前单词word本身为回文，且words中存在空串，则将空串下标bidx与idx加入答案

2). 若当前单词的逆序串在words中，则将逆序串下标ridx与idx加入答案
this is for non-palindrome

3). 将当前单词word拆分为左右两半left，right。

     3.1) 若left为回文，并且right的逆序串在words中，则将right的逆序串下标rridx与idx加入答案
     
     3.2) 若right为回文，并且left的逆序串在words中，则将left的逆序串下标idx与rlidx加入答案


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
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
	 bool isPalin(string& s, int start, int end) {
		 while (start<end) {
			 if(s[start]!=s[end]) return false;
			 start++;
			 end--;
		 }

		 return true;
	 }

	 string revertString(string s) {
		 string res=s;
		 int l=0, r=res.size()-1;
		 while (l<r) {
			 char tmp=res[l];
			 res[l]=res[r];
			 res[r]=tmp;
			 l++;
			 r--;
		 }

		 return res;
	 }

     vector<vector<int>> palindromePairs(vector<string>& words) {
    	 set<vector<int> > res;
    	 map<string, int> dict;
    	 int size=words.size();

    	 for (int i=0; i<size; i++) {
    		 dict[words[i]] = i;
    	 }

    	 for (int i=0; i<size; i++) {
    		 if (words[i].size()==0) continue;

    		 if (isPalin(words[i], 0, words[i].size()-1)) {
    			 auto iter=dict.find("");
    			 if (iter!=dict.end()) {
    				 vector<int> v1 = {i, iter->second};
    				 vector<int> v2 = {iter->second, i};
    				 res.insert(v1);
    				 res.insert(v2);
    			 }
    		 } else {
				 string revert=revertString(words[i]);
				 auto iter=dict.find(revert);
				 if (iter!=dict.end()) {
					 vector<int> v1 = {i, iter->second};
					 vector<int> v2 = {iter->second, i};
					 res.insert(v1);
					 res.insert(v2);
				 }
    		 }

    		 // j is the start of right part of words[i]
    		 for (int j=1; j<words[i].size(); j++) {
    			 string left, right;
    			 left=words[i].substr(0, j);
    			 right=words[i].substr(j, words.size()-j);

    			 if (isPalin(left, 0, left.size()-1)) {
    				 string revert=revertString(right);
    				 auto iter=dict.find(revert);
    				 if (iter!=dict.end()) {
    					 vector<int> v={iter->second, i};
    					 res.insert(v);
    				 }
    			 }

    			 if (isPalin(right, 0, right.size()-1)) {
    				 string revert=revertString(left);
					 auto iter=dict.find(revert);
					 if (iter!=dict.end()) {
						 vector<int> v={i, iter->second};
						 res.insert(v);
					 }
    			 }
    		 }
    	 }

    	 vector<vector<int> > vres;
    	 for(auto s:res) {
    		 vres.push_back(s);
    	 }
    	 return vres;
     }
 };

int main()
{
	return 0;
}

