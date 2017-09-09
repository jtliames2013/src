给一个n-nery tree 和它的一个copy，参数传进来的是一个原树上的某的node，让你返回copy tree对应的node：
这个题，我开始以为是clone graph类似的那个题，他们说的不是很清楚，我开始以为是返回1-1映射的node；后来澄清才发现不是。

BFS
struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	TreeNode* findNode(TreeNode *orig, TreeNode *copy, TreeNode* target) {
		if (orig==NULL || copy==NULL || target==NULL) return NULL;
		if (orig==target) return copy;
		queue<TreeNode*> q1, q2;
		q1.push(orig);
		q2.push(copy);

		while (!q1.empty()) {
			TreeNode* f1=q1.front();
			q1.pop();
			TreeNode* f2=q2.front();
			q2.pop();
			if (f1==target) return f2;
			for (auto c:f1->children) q1.push(c);
			for (auto c:f2->children) q2.push(c);
		}

		return NULL;
	}
};

DFS
class Solution {
public:
	TreeNode* dfs(TreeNode *orig, TreeNode *copy, TreeNode* target) {
		if (orig==NULL || copy==NULL || target==NULL) return NULL;
		if (orig==target) return copy;
		for (int i=0; i<orig->children.size(); i++) {
			TreeNode *n=dfs(orig->children[i], copy->children[i], target);
			if (n!=NULL) return n;
		}
		return NULL;
	}

	TreeNode* findNode(TreeNode *orig, TreeNode *copy, TreeNode* target) {
		return dfs(orig, copy, target);
	}
};

