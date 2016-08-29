Tree的遍历，比较基本
n-ary tree，value是String，首先让把所有node的value concat成一个string返回，顺序自选（先／中／后）。
followup是让你encode成string和decode成tree。

第一题很基本，最简单的递归. 
第二题我说要么转化成inorder和preorder，再还原；或者可以加标记，比如第一层节点加一个*，第二层加两个**。他让我写第二个。encode还比较好写，decode的时候我要用brute force，他问我时间我说N^2，他说不好有没有更好的方法，我跟他讨论半天最后没时间就说说思路，用map存储child和parent，再还原成tree。最后问两个问题就完了。

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

