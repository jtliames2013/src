把一棵随机的树，变成一个string序列，使得这个序列能够reconstruct the random tree. random tree 就是说这课树的任意节点可能有多个子节点

struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	void serialize(string& res, TreeNode *root) {
		if (root==NULL) return;
		if (!res.empty()) res+=",";
		res+=to_string(root->val);
		for (int i=0; i<root->children.size(); i++) {
			serialize(res, root->children[i]);
		}
		res+=",#";
	}
	string serialize(TreeNode *root) {
		string res;
		serialize(res, root);
		return res;
	}


	TreeNode* deserialize(istringstream& iss) {
		string val;
		if (!getline(iss, val, ',')) return NULL;
		if (val=="#") return NULL;
		TreeNode *n=new TreeNode(stoi(val));
		while (1) {
			TreeNode *child=deserialize(iss);
			if (child==NULL) break;
			n->children.push_back(child);
		}
		return n;
	}

	TreeNode* deserialize(string data) {
		istringstream iss(data);
		return deserialize(iss);
	}
};

int main()
{
	Solution s;
	string str="1,2,4,#,5,#,#,3,6,#,7,#,#,#";
	TreeNode *root=s.deserialize(str);
	string res=s.serialize(root);
	cout << res << endl;
	return 0;
}

