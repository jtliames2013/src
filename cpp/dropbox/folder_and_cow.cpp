75分钟一道题，题目特别长，读题理解题意花了我20分钟，实际比较简单，题目长的都是纸老虎。简单地说就是一个多叉树，每一个节点(folder)可以是share或者private的，每一个节点有个membershipList（cows），子节点如果是share的，可以继承父节点的membershipList，否则不行。给了一堆输入信息，判断有哪些cows是所有叶子folder都可以access的（在所有叶子folder的membershipList里）。

做法就是找到根节点，然后往下遍历，把自己的membershipList传下去，子节点如果自己是share的，就把父节点传来的membershipList的cows都加到自己里面。到叶子节点的时候记录下其membershipList里的cow能够access这个节点了，然后遍历所有cow，哪些access节点数目不等于总叶子数，就是不能access所有节点的。
比如
      Shared (1, 2)
      /          \
Shared (1, 3)   Private (2, 3)
结果就是 2和3
3本来就是两个叶子的member，所以可以
左叶子可以继承父节点的membershipList，所以2可以access所有叶子，而又子树是private，不能继承父节点，所以1不行。

struct TreeNode {
	int id;
	bool share;
	bool root;
	unordered_set<int> children;
	unordered_set<int> cows;
	TreeNode(int i):id(i), share(false), root(true) {}
};

void dfs(int id, unordered_map<int, TreeNode*>& nodes, unordered_set<int>& visited, vector<int>& cowCount) {
	visited.insert(id);
	if (nodes[id]->children.size()==0) {
		for (auto i:nodes[id]->cows) cowCount[i]++;
	} else {
		for (auto child:nodes[id]->children) {
			if (visited.find(child)==visited.end()) {
				if (nodes[child]->share) {
					for (auto c:nodes[id]->cows) {
						nodes[child]->cows.insert(c);
					}
				}
				dfs(child, nodes, visited, cowCount);
			}
		}
	}
}

int main() {
	unordered_map<int, TreeNode*> nodes;
	int Q, M, N;
	cin >> Q >> M >> N;
	vector<int> cowCount(Q);
	int count=M+N;
	while (count) {
		int id, K;
		cin >> id >> K;
		TreeNode *node=new TreeNode(id);
		if (count>N) node->share=true;
		while (K) {
			int cow;
			cin >> cow;
			node->cows.insert(cow);
			K--;
		}
		nodes[id]=node;
		count--;
	}

	int G;
	cin >> G;
	while (G) {
		int U, V;
		cin >> U >> V;
		nodes[U]->children.insert(V);
		nodes[V]->root=false;
		G--;
	}

	int leafCount=0;
	for (auto iter:nodes) {
		if (iter.second->children.size()==0) leafCount++;
	}

	unordered_set<int> visited;
	for (auto iter:nodes) {
		if (iter.second->root && visited.find(iter.first)==visited.end()) {
			dfs(iter.first, nodes, visited, cowCount);
		}
	}

	vector<int> res;
	for (int i=0; i<Q; i++) {
		if (cowCount[i]<leafCount) res.push_back(i);
	}

	/*
	 * input
	 * 3
	 * 2 1
	 * 1 1 0
	 * 2 1 1
	 * 3 3 0 1 2
	 * 2
	 * 1 2
	 * 1 3
	 * output
	 * 2
	 */

	for (auto i:res) cout << i << " ";
	cout << endl;
	return 0;
}

