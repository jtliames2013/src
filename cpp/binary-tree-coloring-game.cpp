1145. Binary Tree Coloring Game
Medium

139

33

Favorite

Share
Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false.

 

Example 1:


Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
Output: true
Explanation: The second player can choose the node with value 2.
 

Constraints:

root is the root of a binary tree with n nodes and distinct node values from 1 to n.
n is odd.
1 <= x <= n <= 100

1.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* first=find(root, x);
        int left=count(first->left);
        int right=count(first->right);
        return max({left, right, n-left-right-1})>n/2;
    }
private:
    TreeNode* find(TreeNode* root, int x) {
        if (root==NULL) return NULL;
        if (root->val==x) return root;
        auto l=find(root->left, x);
        auto r=find(root->right, x);
        return l==NULL?r:l;
    }

    int count(TreeNode* root) {
        if (root==NULL) return 0;
        auto l=count(root->left);
        auto r=count(root->right);
        return l+r+1;
    }
};

2.
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int left=0, right=0;
        count(root, left, right, x);
        return max({left, right, n-left-right-1})>n/2;
    }
private:
    int count(TreeNode* root, int& left, int& right, int x) {
        if (root==NULL) return 0;
        auto l=count(root->left, left, right, x);
        auto r=count(root->right, left, right, x);
        if (root->val==x) { left=l; right=r; }
        return l+r+1;
    }
};
