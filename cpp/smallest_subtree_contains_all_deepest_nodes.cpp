Given a tree, find the smallest subtree that contains all of the tree's deepest nodes.
                  a. 
               /  |  \
             b   c   d. 
           /   \       |
         e      f      g
       /       /  \
      h      i     j
depth of tree: 4
deepest nodes:[h,i,j]
least common ancestor of [h,i,j]: b
return: b

struct MultiTreeNode {
	  int val;
	  vector<MultiTreeNode*> children;
	  MultiTreeNode(int v) : val(v) {}
  };

class Solution {
	void findDepth(MultiTreeNode *root, map<MultiTreeNode*, int>& depth) {
		if (root==NULL) return;
		if (root->children.size()==0) {
			depth[root]=1;
			return;
		}

		int maxDepth=0;
		for (int i=0; i<root->children.size(); i++) {
			int d=findDepth(root->children[i], depth);
			maxDepth=max(maxDepth, d)+1;
		}
		depth[root]=maxDepth;
	}
	MultiTreeNode* findSubTree(MultiTreeNode *root) {
		map<MultiTreeNode*, int> depth;
		findDepth(root, depth);

		while (root!=NULL) {
			if (root->children.size()>0) {
				MultiTreeNode *maxNode=root->children[0];
				int maxDepth=depth[root->children[0]];
				int maxCnt=1;
				for (int i=1; i<root->children.size(); i++) {
					if (depth[root->children[i]]>maxDepth) {
						maxNode=root->children[i];
						maxDepth=depth[root->children[i]];
						maxCnt=1;
					} else if (depth[root->children[i]]==maxDepth) {
						maxCnt++;
					}
				}

				if (maxCnt==1) root=maxNode;
				else break;
			} else {
				break;
			}
		}

		return root;
	}
};

