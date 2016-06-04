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

 class TrieNode {
 public:
     // Initialize your data structure here.
 	map<char, TrieNode*> children;
 	bool isWord;

 	TrieNode() {
 		isWord=false;
     }
 };

 class Trie {
 public:
     Trie() {
         root = new TrieNode();
     }

     // Inserts a word into the trie.
     void insert(string word) {
     	int i=0;
     	TrieNode* n=root;
     	while (i<word.size()) {
     		auto res=n->children.find(word[i]);
     		if (res==n->children.end()) {
     			break;
     		} else {
     			n=(*res).second;
     			i++;
     		}
     	}

     	TrieNode *curr;
     	while (i<word.size()) {
     		curr=new TrieNode();
     		n->children.insert(make_pair(word[i], curr));
     		n=curr;
     		i++;
     	}

     	n->isWord=true;
     }

     void deleteW(string word) {
    	 vector<TrieNode*> v;
    	 TrieNode* n=root;
    	 v.push_back(n);
    	 for (int i=0; i<word.size(); i++) {
    		 auto res=n->children.find(word[i]);
    		 if (res == n->children.end()) return;
    		 n=(*res).second;
    		 v.push_back(n);
    	 }

    	 if (n->isWord) {
    		 v[v.size()-1]->isWord=false;
    		 for (int i=v.size()-1; i>0; i--) {
    			 if (v[i-1]->children.size()==1) {
    				 v[i-1]->children.clear();
    				 delete v[i];
    			 } else {
    				 break;
    			 }
    		 }
    	 }
     }

     // Returns if the word is in the trie.
     bool search(string word) {
     	TrieNode* n=root;
     	for (int i=0; i<word.size(); i++) {
     		auto res = n->children.find(word[i]);
     		if (res==n->children.end()){
     			return false;
     		} else {
     			n=(*res).second;
     		}
     	}

     	return n->isWord;
     }

     // Returns if there is any word in the trie
     // that starts with the given prefix.
     bool startsWith(string prefix) {
     	TrieNode* n=root;
     	for (int i=0; i<prefix.size(); i++) {
     		auto res = n->children.find(prefix[i]);
     		if (res==n->children.end()){
     			return false;
     		} else {
     			n=(*res).second;
     		}
     	}

     	return true;
     }

     TrieNode* root;
 };

 class Solution {
 public:
	 void findWordsInBoard(vector<vector<char>>& board, Trie& tree, int row, int col, vector<vector<bool>>& visited, vector<string>& res, string& prefix, TrieNode* node) {
		 auto iter=node->children.find(board[row][col]);
		 if (iter != node->children.end()) {
			 if (iter->second->isWord) {
				 prefix.push_back(iter->first);
				 res.push_back(prefix);
				 tree.deleteW(prefix);
				 prefix.erase(prefix.end()-1);
			 }
		 }

		 if (iter != node->children.end()) {
			 visited[row][col]=true;

			 if (row>0) {
				 if (visited[row-1][col]==false) {
					 prefix.push_back(iter->first);
					 findWordsInBoard(board, tree, row-1, col, visited, res, prefix, iter->second);
					 prefix.erase(prefix.end()-1);
				 }
			 }

		 	 if (col>0) {
				 if (visited[row][col-1]==false) {
					 prefix.push_back(iter->first);
					 findWordsInBoard(board, tree, row, col-1, visited, res, prefix, iter->second);
					 prefix.erase(prefix.end()-1);
				 }
			 }

		 	 if (row<board.size()-1) {
				 if (visited[row+1][col]==false) {
					 prefix.push_back(iter->first);
					 findWordsInBoard(board, tree, row+1, col, visited, res, prefix, iter->second);
					 prefix.erase(prefix.end()-1);
				 }
			 }

			 if (col<board[0].size()-1) {
				 if (visited[row][col+1]==false) {
					 prefix.push_back(iter->first);
					 findWordsInBoard(board, tree, row, col+1, visited, res, prefix, iter->second);
					 prefix.erase(prefix.end()-1);
				 }
			 }

			 visited[row][col]=false;
		 }
	 }

     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	 vector<string> res;
    	 int row=board.size();
    	 if (row==0) return res;
    	 int col=board[0].size();
    	 if (col==0) return res;
    	 if (words.size()==0) return res;
    	 vector<vector<bool> > visited(row, vector<bool>(col, false));
    	 string prefix;
    	 Trie prefixTree;
    	 for (int k=0; k<words.size(); k++) {
    		 prefixTree.insert(words[k]);
    	 }

    	 for (int i=0; i<row; i++) {
    		 for (int j=0; j<col; j++) {
    			 findWordsInBoard(board, prefixTree, i, j, visited, res, prefix, prefixTree.root);
    		 }
    	 }

    	 sort(res.begin(), res.end());
    	 return res;
     }
 };

int main()
{
	return 0;
}

