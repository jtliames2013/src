nclude <stdio.h>
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

class Codec {
public:
	void serialize(TreeNode* root, string& res) {
		if (root!=NULL) {
			char buf[64];
			sprintf(buf, "%d", root->val);
			res.append(buf);
			res.append(",");
			serialize(root->left, res);
			serialize(root->right, res);
		} else {
			res.append("#");
			res.append(",");
		}
	}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string res;
    	if (root==NULL) return res;

    	serialize(root, res);

    	return res;
    }

    string getNext(string& data, int index, int& nextIndex) {
    	int i=data.find_first_of(",", index);
    	if (i!=-1) {
    		nextIndex=i+1;
    		return data.substr(index, i-index);
    	} else {
    		nextIndex=-1;
    		return "";
    	}
    }

    TreeNode* deserialize(string data, int index, int& nextIndex) {
    	string s=getNext(data, index, nextIndex);
    	if (s.empty() || s.compare("#")==0) return NULL;

    	TreeNode *n=new TreeNode(atoi(s.c_str()));
    	n->left=deserialize(data, nextIndex, nextIndex);
    	n->right=deserialize(data, nextIndex, nextIndex);

    	return n;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if (data.empty()) return NULL;
    	int nextIndex=0;
    	return deserialize(data, 0, nextIndex);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
	TreeNode *t1=new TreeNode(1);
	TreeNode *t2=new TreeNode(2);
	t1->left=t2;

	Codec c;
	string s=c.serialize(t1);
	TreeNode *n=c.deserialize(s);
	return 0;
}


