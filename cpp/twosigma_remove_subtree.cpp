1. Remove subtree from a tree，然後每個 node 有自己的 value, parent index, 跟 bool for valid or invalid 

一个Array[Nodes]. Node包含［parent，value，valid］，给一个index，删除一个子树，然后更新这个valid，true表示还在，false表示删了，让我不能malloc空间，但是可以递归。

struct TreeNode {
	int val;
	int parent;
	bool valid;
	bool visited;
	TreeNode(int v): val(v), parent(-1), valid(true), visited(false) {}
};

class Solution {
public:
	bool dfs(vector<TreeNode*>& tree, int idx) {
		tree[idx]->visited=true;
		if (tree[idx]->valid==false) return false;
		if (tree[idx]->parent==-1) return true;

		if (dfs(tree, tree[idx]->parent)==false) {
			tree[idx]->valid=false;
			return false;
		}

		return true;
	}
	void removeSubTree(vector<TreeNode*>& tree, int node) {
		int n=tree.size();
		tree[node]->valid=false;
		tree[node]->visited=true;
		for (int i=0; i<n; i++) {
			if (tree[i]->visited==true) continue;
			dfs(tree, i);
		}
	}
};

