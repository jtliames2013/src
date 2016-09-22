打印binary tree 一条最长的路径

class Solution {
public:
	int getLongestDepth(TreeNode *root) {
		if (root==NULL) return 0;
		if (root->left==NULL&&root->right==NULL) return 1;
		int depth=0;
		if (root->left!=NULL) {
			depth=max(depth, getLongestDepth(root->left));
		}
		if (root->right!=NULL) {
			depth=max(depth, getLongestDepth(root->right));
		}

		return depth;
	}

	bool printPath(TreeNode *root, vector<TreeNode*>& path, int depth) {
		if (root==NULL) return false;
		path.push_back(root);

		if (path.size()==depth) {
			for (int i=0; i<path.size(); i++) {
				cout << path[i]->val << " ";
			}
			cout << endl;
			return true;
		}

		if (root->left) {
			if (printPath(root->left, path, depth)) return true;
		}

		if (root->right) {
			if (printPath(root->right, path, depth)) return true;
		}

		path.pop_back();
		return false;
	}

	void printLongestPath(TreeNode *root) {
		vector<TreeNode*> path;
		int depth=getLongestDepth(root);
		printPath(root, path, depth);
	}
};

