297. Serialize and Deserialize Binary Tree My Submissions QuestionEditorial Solution
Total Accepted: 22622 Total Submissions: 79127 Difficulty: Hard
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.

Hide Company Tags LinkedIn Google Uber Facebook Amazon Microsoft Yahoo Bloomberg
Hide Tags Tree Design
Hide Similar Problems (M) Encode and Decode Strings


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


2. use istringstream

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Codec {

public:

    void serialize(TreeNode *root, string& res) {

        string str;

        if (root==NULL) {

            str="#";

        } else {

            str=to_string(root->val);

        }

        if (!res.empty()) {

            res += ",";

        }

        res += str;



        if (root!=NULL) {

            serialize(root->left, res);

            serialize(root->right, res);

        }

    }

    

    // Encodes a tree to a single string.

    string serialize(TreeNode* root) {

        string res;

        serialize(root, res);

        

        return res;

    }



    TreeNode* deserialize(istringstream& iss) {

        string val;

        if (!getline(iss, val, ',')) return NULL;

        if (val=="#") return NULL;

        

        TreeNode *n=new TreeNode(stoi(val, nullptr));

        TreeNode *l=deserialize(iss);

        TreeNode *r=deserialize(iss);

        n->left=l;

        n->right=r;

        return n;

    }

    

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {

        istringstream iss(data);

        

        return deserialize(iss);

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


