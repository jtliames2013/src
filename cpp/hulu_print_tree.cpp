class TreeNode {
public:
	int val;
	vector<TreeNode*> children;
	TreeNode(int v): val(v) {}
	void printNode(string indent) {
		cout << indent << val << endl;
		for (int i=0; i<children.size(); i++) {
			children[i]->printNode(indent+"+");
		}
	}
};

class Solution {
public:
	void printTree(TreeNode* root, string indent) {
		cout << indent << root->val << endl;
		for (int i=0; i<root->children.size(); i++) {
			printTree(root->children[i], indent+"+");
		}
	}
};

int main()
{
	Solution s;
	TreeNode *n1=new TreeNode(1);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	TreeNode *n4=new TreeNode(4);
	TreeNode *n5=new TreeNode(5);
	TreeNode *n6=new TreeNode(6);
	TreeNode *n7=new TreeNode(7);
	n1->children.push_back(n2);
	n1->children.push_back(n3);
	n2->children.push_back(n4);
	n2->children.push_back(n5);
	n3->children.push_back(n6);
	n3->children.push_back(n7);
	n1->printNode("");
	s.printTree(n1, "");
	return 0;
}

