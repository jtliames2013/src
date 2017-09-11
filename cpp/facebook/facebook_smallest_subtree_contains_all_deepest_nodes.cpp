Given a tree, find the smallest subtree that contains all of the tree's deepest nodes.
                  a. 
               /  |  \
             b   c   d. 
           /   \       |
         e      f      g
       /       /  \
      h      i     j
depth of tree: 4
deepest nodes:[h,i,j]
least common ancestor of [h,i,j]: b
return: b

1 Recursive
struct MultiTreeNode {
	  int val;
	  vector<MultiTreeNode*> children;
	  MultiTreeNode(int v) : val(v) {}
  };

class Solution {
	pair<MultiTreeNode*,int> findSubTree(MultiTreeNode *root) {
		if (root==NULL) return {NULL, 0};

		int maxDepth=0, maxCnt=0;
		MultiTreeNode* maxNode;

		for (int i=0; i<root->children.size(); i++) {
			int p=findSubTree(root->children[i]);
			if (p.second>maxDepth) {
				maxDepth=p.second;
				maxCnt=1;
				maxNode=p.first;
			} else if (p.second==maxDepth) {
				maxCnt++;
		}

		if (maxCnt==1) {
			return {maxNode, maxDepth+1};
		} else {
			return {root, maxDepth+1};
		}
	}
};

2. Cache depth
class Solution {
	int findDepth(MultiTreeNode *root, map<MultiTreeNode*, int>& depth) {
		if (root==NULL) return 0;
        int maxDepth=1;
		if (root->children.size()==0) {
			depth[root]=maxDepth;
			return maxDepth;
		}

		int maxDepth=0;
		for (int i=0; i<root->children.size(); i++) {
			int d=findDepth(root->children[i], depth);
			maxDepth=max(maxDepth, d+1);
		}
		depth[root]=maxDepth;
        return maxDepth;
	}
	MultiTreeNode* findSubTree(MultiTreeNode *root) {
		map<MultiTreeNode*, int> depth;
		findDepth(root, depth);

		while (root!=NULL) {
			if (root->children.size()>0) {
				MultiTreeNode *maxNode=root->children[0];
				int maxDepth=depth[root->children[0]];
				int maxCnt=1;
				for (int i=1; i<root->children.size(); i++) {
					if (depth[root->children[i]]>maxDepth) {
						maxNode=root->children[i];
						maxDepth=depth[root->children[i]];
						maxCnt=1;
					} else if (depth[root->children[i]]==maxDepth) {
						maxCnt++;
					}
				}

				if (maxCnt==1) root=maxNode;
				else break;
			} else {
				break;
			}
		}

		return root;
	}
};

给一个 二叉树 ， 求最深节点的最小公共父节点。

     1
  2   3
     5  6    return 3.

       1  
    2   3
4      5 6   retrun 1. 

1. Recursive
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	pair<TreeNode*,int> findSubTree(TreeNode* root) {
		if (root==NULL) return {NULL, 0};
		int depth;
		pair<TreeNode*,int> l=findSubTree(root->left);
		pair<TreeNode*,int> r=findSubTree(root->right);
		depth=max(l.second, r.second)+1;
		if (l.second==r.second) {
			return {root, depth};
		} else if (l.second>r.second) {
			return {l.first, depth};
		} else {
			return {r.first, depth};
		}
	}
};

2. Iterative
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	TreeNode *lca(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root==NULL|| p==NULL || q==NULL) return NULL;
		if (root==p || root==q) return root;
		TreeNode *l=lca(root->left, p, q);
		TreeNode *r=lca(root->right, p, q);
		if (l!=NULL && r!=NULL) return root;
		else if (l==NULL) return r;
		else if (r==NULL) return l;
		else return NULL;
	}

	TreeNode* findSubTree(TreeNode* root) {
		if (root==NULL) return NULL;
		TreeNode *head=root, *tail=root;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size=q.size();
			for (int i=0; i<size; i++) {
				TreeNode* f=q.front();
				q.pop();
				if (i==0) head=f;
				if (i==size-1) tail=f;
				if (f->left) q.push(f->left);
				if (f->right) q.push(f->right);
			}
		}

		if (head==tail) return head;
		else {
			return lca(root, head, tail);
		}
	}
};

3. Cache depth
class Solution {
	int findDepth(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
		if (root==NULL) return;
		int depth=1;
		if (root->left) {
			depth=max(depth, findDepth(root->left, mp)+1);
		}
		if (root->right) {
			depth=max(depth, findDepth(root->right, mp)+1);
		}

		mp[root]=depth;
		return depth;
	}

	TreeNode* findSubTree(TreeNode* root) {
		unordered_map<TreeNode*, int> mp;
		findDepth(root, mp);
		while (root) {
			if (root->left && root->right) {
				if (mp[root->left]==mp[root->right]) break;
				else if (mp[root->left]>mp[root->right]) root=root->left;
				else root=root->right;
			} else if (root->left){
				root=root->left;
			} else if (root->right) {
				root=root->right;
			} else {
				break;
			}
		}
		return root;
	}
};

