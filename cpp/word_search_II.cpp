212. Word Search II 
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

Hide Company Tags Microsoft Google Airbnb
Hide Tags Backtracking Trie
Hide Similar Problems (M) Word Search

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

2. modify delete in Trie

class Solution {
public:
    class TrieNode {
    public:
        // Initialize your data structure here.
        bool isWord;
        map<char, TrieNode*> children;
        TrieNode() {
            isWord=false;
        }
    };
    
    class Trie {
    public:
        Trie() {
            root=new TrieNode();
        }
    
        // Inserts a word into the trie.
        void insert(string word) {
    		int size=word.size();
    		int i;
    		TrieNode *n=root;
    		for (i=0; i<size; i++) {
    		    auto iter=n->children.find(word[i]);
    		    if (iter==n->children.end()) break;
    		    n=iter->second;
    		}
    		while (i<size) {
    		    TrieNode *node=new TrieNode();
    		    n->children[word[i]]=node;
    		    n=node;
    		    i++;
    		}
    		n->isWord=true;
        }
    
        void deleteWord(string word) {
            int size=word.size();
            vector<TrieNode*> v;
            int i;
            TrieNode *n=root;
            v.push_back(n);
            for (i=0; i<size; i++) {
                auto iter=n->children.find(word[i]);
                if (iter==n->children.end()) return;
                n=iter->second;
                v.push_back(n);
            }
            
            if (n->children.size()!=0) {
                n->isWord=false;
            } else {
                for (int i=v.size()-1; i>0; i--) {
                    if (v[i]->children.size()==0) {
                        // length of v is one greater than word
                        v[i-1]->children.erase(word[i-1]);
                        delete v[i];
                    } else {
                        break;
                    }
                }
            }
        }
        
        TrieNode* root;
    };

    void findInBoard(vector<vector<char>>& board, Trie& prefixTree, TrieNode* node, vector<vector<bool>>& visited, vector<string>& res, string& prefix, int row, int col, int m, int n) {
            auto iter=node->children.find(board[row][col]);
            if (iter==node->children.end()) return;
            
            prefix.push_back(iter->first);
            if (iter->second->isWord) {
                res.push_back(prefix);
                prefixTree.deleteWord(prefix);
            }
            
            visited[row][col]=true;
            int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
            for (int i=0; i<4; i++) {
                int nx=row+delta[i][0];
                int ny=col+delta[i][1];
                
                if (nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==false) {
                    findInBoard(board, prefixTree, iter->second, visited, res, prefix, nx, ny, m, n);
                }
            }
            visited[row][col]=false;
            prefix.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m=board.size();
        if (m==0) return res;
        int n=board[0].size();
        if (n==0) return res;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string prefix;
        Trie prefixTree;
        for (auto w:words) prefixTree.insert(w);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                findInBoard(board, prefixTree, prefixTree.root, visited, res, prefix, i, j, m, n);
            }
        }
        
        return res;
    }
};

int main()
{
	return 0;
}

