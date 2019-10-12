general tree序列化/反序列化，如何thread safe

#define N 6

struct TreeNode {
	int val;
	TreeNode* children[N];
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	void serialize(TreeNode* root, string& res) {
		if (root==NULL) return;
		if (!res.empty()) res+=",";
		res+=to_string(root->val);
		for (int i=0; i<N; i++) {
			if (root->children[i]!=NULL) {
				serialize(root->children[i], res);
			}
		}
		res+=",#";
	}

	string serialize(TreeNode* root) {
		string res;
		serialize(root, res);
		return res;
	}

	TreeNode* deserialize(istringstream &iss) {
		string val;
		if (!getline(iss, val, ',')) return NULL;
		if (val=="#") return NULL;
		TreeNode *node=new TreeNode(stoi(val));
		for (int i=0; i<N; i++) {
			TreeNode *child=deserialize(iss);
			if (child==NULL) {
				break;
			} else {
				node->children[i]=child;
			}
		}
		return node;
	}

	TreeNode* deserialize(string data) {
		istringstream iss(data);
		return deserialize(iss);
	}
};

int main() {
	Solution s;
	string str="1,2,#,3,#,#";
	TreeNode *root=s.deserialize(str);
	string res=s.serialize(root);
	return 0;
}

2.

struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	void serialize(TreeNode* root, string& res) {
		if (root==NULL) return;
		if (!res.empty()) res+=",";
		res+=to_string(root->val);
		for (int i=0; i<root->children.size(); i++) {
			serialize(root->children[i], res);
		}
		res+=",#";
	}

	string serialize(TreeNode* root) {
		string res;
		serialize(root, res);
		return res;
	}

	TreeNode* deserialize(istringstream &iss) {
		string val;
		if (!getline(iss, val, ',')) return NULL;
		if (val=="#") return NULL;
		TreeNode *node=new TreeNode(stoi(val));
		while (1) {
			TreeNode *child=deserialize(iss);
			if (child==NULL) {
				break;
			} else {
				node->children.push_back(child);
			}
		}
		return node;
	}

	TreeNode* deserialize(string data) {
		istringstream iss(data);
		return deserialize(iss);
	}
};

int main() {
	Solution s;
	string str="1,2,4,#,5,#,#,3,6,#,7,#,#,#";
	TreeNode *root=s.deserialize(str);
	string res=s.serialize(root);
	cout << res << endl;
	return 0;
}

