https://www.hackerrank.com/challenges/even-tree/problem

You are given a tree (a simple connected graph with no cycles). The tree has N nodes numbered from 1 to N.

Find the maximum number of edges you can remove from the tree to get a forest such that each connected component of the forest contains an even number of vertices.

        o
  /    |   |   \
o     o   o    o
|      
o

比如可以删掉一个边变成：
         o
  x    |   |   \
o     o   o    o
|      
o
结果里有两个tree，分别有2个和四个node，符合条件，这就是答案，因为再删就不符合条件了
return是一个list，里面是所有新生成的tree的root

struct TreeNode {
	int val;
	vector<TreeNode*> children;
	TreeNode(int v):val(v) {}
};

class Solution {
public:
	pair<int,int> dfs(TreeNode* root) {
		if (root==NULL) return {0,0};
		int count=0, edges=0;
		for (int i=0; i<root->children.size(); i++) {
			pair<int,int> res=dfs(root->children[i]);
			edges+=res.second;
			if (res.first%2==0) {
				edges++;
			} else {
				count+=res.first;
			}
		}

		count++;
		return {count, edges};
	}

	int findMaximumEdges(TreeNode* root) {
		// {node count, edge to remove}
		pair<int,int> res =dfs(root);
		return res.second;
	}
};

