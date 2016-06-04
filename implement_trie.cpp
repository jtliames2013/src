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

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	return 0;
}

