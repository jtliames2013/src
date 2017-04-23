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
    void serialize(TreeNode* root, string& res) {
        string val;
        if (root==NULL) val="#";
        else val=to_string(root->val);
        if (!res.empty()) res+=",";
        res+=val;
        
        if (root) {
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
        
        TreeNode *n=new TreeNode(stoi(val));
        n->left=deserialize(iss);
        n->right=deserialize(iss);
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

