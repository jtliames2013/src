Find path from one node to another node in a binary tree
node has parent pointer

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode *parent;
     TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
	vector<int> findPath(TreeNode* t1, TreeNode* t2) {
		vector<int> res, left, right;
		int l1=0, l2=0;
		TreeNode* n=t1;
		while (n) {
			n=n->parent;
			l1++;
		}
		n=t2;
		while (n) {
			n=n->parent;
			l2++;
		}

		while (l1>l2) {
			left.push_back(t1->val);
			t1=t1->parent;
			l1--;
		}
		while (l2>l1) {
			right.push_back(t2->val);
			t2=t2->parent;
			l2--;
		}

		while (t1!=t2) {
			left.push_back(t1->val);
			right.push_back(t2->val);
			t1=t1->parent;
			t2=t2->parent;
		}

		for (int i=0; i<left.size(); i++) res.push_back(left[i]);
		res.push_back(t1->val);
		for (int i=right.size()-1; i>=0; i--) res.push_back(right[i]);
		return res;
	}
};

