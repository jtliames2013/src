1.1 问一个数组里面最长的连续的递增数列的长度
1.2 如果是一个tree，不一定是binary tree，的最长的连续递增的序列的长度. 
     这一问我是用recursive dfs做的，然后被要求用iterative 做一下。

class Solution {
public:
	int longestSequence(vector<int> nums) {
		int n=nums.size();
		if (n==0) return 0;
		int len=0, res=0;
		for (int i=0; i<n; i++) {
			if (i==0 || nums[i]-nums[i-1]==1) len++;
			else {
				res=max(res, len);
				len=1;
			}
		}
        res=max(res, len);
		return res;
	}
};

struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	int dfs(TreeNode* root, TreeNode* prev, int len) {
		if (root==NULL) return 0;
		if (prev!=NULL && prev->val+1==root->val) len++;
		else len=1;

		for (auto c:root->children) {
			len=max(len, dfs(c, root, len));
		}
		return len;
	}
	int longestSequence(TreeNode* root) {
		return dfs(root, NULL, 0);
	}
};

struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	int longestSequence(TreeNode* root) {
		if (root==NULL) return 0;
		int res=0;
		queue<pair<TreeNode*,int>> q;
		q.push({root,1});
		while (!q.empty()) {
			pair<TreeNode*,int> f=q.front();
			q.pop();

			for (auto c:f.first->children) {
				int len;
				if (c->val==f.first->val+1) len=f.second+1;
				else {
					res=max(res, len);
					len=1;
				}
				q.push({c, len});
			}
			if (f.first->children.empty()) res=max(res, f.second);
		}
		return res;
	}
};

