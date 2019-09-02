449. Serialize and Deserialize BST Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 10346
Total Submissions: 24490
Difficulty: Medium
Contributors:
ben65
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Subscribe to see which companies asked this question.

Hide Tags Tree
Hide Similar Problems (H) Serialize and Deserialize Binary Tree

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start=0;
        return deserialize(data, start, INT_MIN, INT_MAX);
    }

private:
    void serialize(TreeNode* root, string& res) {
        if (root==NULL) return;
        if (!res.empty()) res+=",";
        res+=to_string(root->val);
        
        serialize(root->left, res);
        serialize(root->right, res);
    }
    
    TreeNode* deserialize(string data, int& start, int lower, int upper) {
        if (start>=data.size()) return NULL;
        int i, val=0;
        for (i=start; i<data.size() && data[i]!=','; ++i) {
            val=val*10+data[i]-'0';
        }
        
        if (val<=lower || val>=upper) return NULL;
        start=i+1;
        TreeNode* n=new TreeNode(val);
        n->left=deserialize(data, start, lower, val);
        n->right=deserialize(data, start, val, upper);

        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
