#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

 class Solution {
 public:
     TreeNode* invertTree(TreeNode* root) {
    	 if (root==NULL) return NULL;
    	 TreeNode* left=invertTree(root->right);
    	 TreeNode* right=invertTree(root->left);
    	 root->left=left;
    	 root->right=right;

    	 return root;
     }
 };

int main()
{
	return 0;
}

