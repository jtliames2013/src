struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* clone(TreeNode* root) {
		if (root==NULL) return NULL;
		TreeNode* newRoot=new TreeNode(root->val);
		newRoot->left=clone(root->left);
		newRoot->right=clone(root->right);

		return newRoot;
	}
};

2. With random pointer
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* random;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* cloneLeftRight(TreeNode* root, map<TreeNode*, TreeNode*>& table) {
		if (root==NULL) return NULL;
		TreeNode* newRoot=new TreeNode(root->val);
		table[root]=newRoot;
		newRoot->left=cloneLeftRight(root->left, table);
		newRoot->right=cloneLeftRight(root->right, table);
		return newRoot;
	}

	void cloneRandom(TreeNode* root, TreeNode* newRoot, map<TreeNode*, TreeNode*>& table) {
		if (root==NULL || newRoot==NULL) return;
		newRoot->random=table[root->random];
		cloneRandom(root->left, newRoot->left, table);
		cloneRandom(root->right, newRoot->right, table);
	}

	TreeNode* clone(TreeNode* root) {
		if (root==NULL) return NULL;
		map<TreeNode*, TreeNode*> table;
		TreeNode *newRoot=cloneLeftRight(root, table);
		cloneRandom(root, newRoot, table);

		return newRoot;
	}
};

3. With random pointer, generic graph clone

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* random;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* clone(TreeNode* root) {
		if (root==NULL) return NULL;
		map<TreeNode*, TreeNode*> table;
		set<TreeNode*> visited;
		queue<TreeNode*> q;
		TreeNode* newRoot=new TreeNode(root->val);
		table[root]=newRoot;
		visited.insert(root);
		q.push(root);

		while (!q.empty()) {
			TreeNode* f=q.front();
			q.pop();
			TreeNode* parent=table[f];

			if (table.find(f->left)==table.end()) {
				q.push(f->left);
				visited.insert(f->left);
				TreeNode *node=new TreeNode(f->left->val);
				table[f->left]=node;
			}
			parent->left=table[f->left];

			if (table.find(f->right)==table.end()) {
				q.push(f->right);
				visited.insert(f->right);
				TreeNode *node=new TreeNode(f->right->val);
				table[f->right]=node;
			}
			parent->right=table[f->right];

			if (table.find(f->random)==table.end()) {
				q.push(f->random);
				visited.insert(f->random);
				TreeNode *node=new TreeNode(f->random->val);
				table[f->random]=node;
			}
			parent->random=table[f->random];
		}

		return newRoot;
	}
};


