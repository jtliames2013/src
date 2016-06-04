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
	map<char, TrieNode*> children;
	bool isWord;

	TrieNode() {
		isWord=false;
	}
};

class WordDictionary {
public:
	TrieNode *root;
	WordDictionary() {
		root=new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
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

    bool find(string& word, int startIndex, TrieNode* node) {
    	if (startIndex==word.size()) {
    		return node->isWord;
    	}

    	if (word[startIndex]=='.') {
    		for(auto child:node->children) {
    			if (find(word, startIndex+1, child.second)) return true;
    		}
    	} else {
    		auto res=node->children.find(word[startIndex]);
    		if (res!=node->children.end()) {
    			return find(word, startIndex+1, (*res).second);
    		}
    	}

    	return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	return find(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
	return 0;
}

