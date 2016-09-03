一个binary tree给你俩node，让你把从一个Node到另一个的路径print出来。这俩Node都一定在tree里。其实就是Lowest common ancestor。

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode*>& path) {
		if (root==NULL||node==NULL) return false;
		if (root==node) {
			path.push_back(root);
			return true;
		}

		path.push_back(root);

		if (root->left) {
			if (findPath(root->left, node, path)) return true;
		}

		if (root->right) {
			if (findPath(root->right, node, path)) return true;
		}

		path.pop_back();
		return false;
	}

	vector<int> getPath(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1, path2;
		findPath(root, p, path1);
		findPath(root, q, path2);

		int i;
		for (i=0; i<path1.size() && i<path2.size(); i++) {
			if (path1[i]!=path2[i]) break;
		}

		vector<int> res;
		for (int j=path1.size()-1; j>=i-1; j--) {
			res.push_back(path1[j]->val);
		}
		for (int j=i; j<path2.size(); j++) {
			res.push_back(path2[j]->val);
		}

		return res;
	}
};

void printPath(vector<int> path) {
	for (int i=0; i<path.size(); i++) {
		cout << path[i] << " ";
	}
	cout << endl;
}

int main() {
	Solution s;
	TreeNode *n1=new TreeNode(0);
	TreeNode *n2=new TreeNode(1);
	TreeNode *n3=new TreeNode(2);
	TreeNode *n4=new TreeNode(3);
	TreeNode *n5=new TreeNode(4);
	n1->left=n2;
	n2->right=n4;
	n1->right=n3;
	n3->left=n5;
	vector<int> path=s.getPath(n1, n4, n5);
	printPath(path);
	return 0;
}

