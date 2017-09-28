Inorder Tree Traversal without recursion and without stack!
Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree.

1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left


一、中序遍历

步骤：

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void inorderMorrisTraversal(TreeNode *root) {
		TreeNode *curr=root, *prev=NULL;
		while (curr!=NULL) {
			if (curr->left==NULL) {
				cout << curr->val << endl;
				curr=curr->right;
			} else {
				prev=curr->left;
				while (prev->right!=NULL && prev->right!=curr) {
					prev=prev->right;
				}

				if (prev->right==NULL) {
					prev->right=curr;
					curr=curr->left;
				} else {
					prev->right=NULL;
					cout << curr->val << endl;
					curr=curr->right;
				}
			}
		}
	}
};


2. Tree Node has parent pointer

1. Initialize current node as root
2. Initialize a flag: leftdone = false;
3. Do following while root is not NULL
     a) If leftdone is false, set current node as leftmost
        child of node. 
     b) Mark leftdone as true and print current node.
     c) If right child of current nodes exists, set current
        as right child and set leftdone as false.
     d) Else If parent exists, If current node is left child
        of its parent, set current node as parent. 
        If current node is right child, keep moving to ancestors
        using parent pointer while current node is right child
        of its parent.  
     e) Else break (We have reached back to root)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
	void inorderTraversal(TreeNode *root) {
		bool leftdone=false;
		while (root) {
			if (!leftdone) {
				while (root->left) root=root->left;
			}

			cout << root->val << endl;

			leftdone=true;

			if (root->right) {
				leftdone=false;
				root=root->right;
			} else if (root->parent) {
				// right node need to move up to visit parent first
				while (root->parent && root==root->parent->right) {
					root=root->parent;
				}
				if (root->parent==NULL) break;
				root=root->parent;
			} else {
				break;
			}
		}
	}
};

