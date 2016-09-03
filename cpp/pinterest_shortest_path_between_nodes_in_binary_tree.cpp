shortest path between 2 nodes in the tree.  LZ用的LCA  然后Heigh(p)+heigh(q)-2*heigh(LCA)

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool findPath(TreeNode* root, TreeNode *node, vector<TreeNode*>& path) {
		if (root==NULL) return false;
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

    int shortestPath(TreeNode* root, TreeNode* p, TreeNode* q) {
    	int res=0;
    	vector<TreeNode*> path1;
    	findPath(root, p, path1);
    	res+=path1.size();
    	vector<TreeNode*> path2;
    	findPath(root, q, path2);
    	res+=path2.size();

    	int count=0;
    	for (int i=0; i<path1.size() && i<path2.size(); i++) {
    		if (path1[i]!=path2[i]) break;
    		count++;
    	}

    	return res-2*count;
    }
};

int main() {
	Solution s;
	TreeNode *n1=new TreeNode(0);
	TreeNode *n2=new TreeNode(1);
	TreeNode *n3=new TreeNode(2);
	n1->left=n2;
	n1->right=n3;
	int res=s.shortestPath(n1, n2, n3);

	return 0;
}


