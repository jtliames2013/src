http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/

Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. See following examples.

The following trees are examples of Complete Binary Trees
    1
  /   \
 2     3
  
       1
    /    \
   2       3
  /
 4

       1
    /    \
   2      3
  /  \    /
 4    5  6
The following trees are examples of Non-Complete Binary Trees
    1
      \
       3
  
       1
    /    \
   2       3
    \     /  \   
     4   5    6

       1
    /    \
   2      3
         /  \
        4    5

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCompleteBT(TreeNode *root) {
	if (root==NULL) return true;
	queue<TreeNode*> q;
	// Create a flag variable which will be set true
	// when a non full node is seen
	bool flag=false;
	q.push(root);

	while (!q.empty()) {
		TreeNode *f=q.front();
		q.pop();

		if (f->left) {
			if (flag) return false;
			q.push(f->left);
		} else {
			flag=true;
		}

		if (f->right) {
			if (flag) return false;
			q.push(f->right);
		} else {
			flag=true;
		}
	}
	return true;
}

