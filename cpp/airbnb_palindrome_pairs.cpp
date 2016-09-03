336. Palindrome Pairs  
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google Airbnb
Hide Tags Hash Table String Trie
Hide Similar Problems (M) Longest Palindromic Substring (H) Shortest Palindrome

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

2.
class Solution {
public:
    bool isPalin(string s) {
        int l=0, r=(int)s.size()-1;
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> idx;
        for (int i=0; i<words.size(); i++) {
            idx[words[i]]=i;
        }
        
        for (int i=0; i<words.size(); i++) {
            // skip empty string
            if (words[i].size()==0) continue;
            
            // abcd
            // left from "" to "abc"
            // right from "abcd" to "d"
            for (int j=0; j<(int)words[i].size(); j++) {
                string left=words[i].substr(0, j);
                string right=words[i].substr(j, words[i].size()-j);
                
                if (isPalin(left)) {
                    string rev=right;
                    reverse(rev.begin(), rev.end());
                    auto iter=idx.find(rev);
                    // note order of index.
                    // if left is empty and if word is palindrome, it'll find the word itself
                    // and we don't want to include it
                    if (iter!=idx.end() && iter->second!=i) res.push_back({iter->second,i});
                }
                
                if (isPalin(right)) {
                    string rev=left;
                    reverse(rev.begin(), rev.end());
                    auto iter=idx.find(rev);
                    // note order of index
                    if (iter!=idx.end()) {
                        res.push_back({i,iter->second});
                        // if word is palindrome, "" can be both before or after it
                        if (left.empty()) res.push_back({iter->second, i});
                    }
                }
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}

