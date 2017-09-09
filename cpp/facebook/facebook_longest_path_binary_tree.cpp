2. longest PATH(could be the path from leaf to leaf) in binary tree

class Solution {
public:
	int maxPath(TreeNode* root, int& longest) {
		if (root==NULL) return 0;
		int l=maxPath(root->left, longest);
		int r=maxPath(root->right, longest);
		longest=max(longest, r+l+1);
		return max(r, l)+1;
	}

    int maxPath(TreeNode* root) {
        int longest=0;
        maxPath(root, longest);
        return longest
    }
};

