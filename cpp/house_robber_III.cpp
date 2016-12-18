337. House Robber III
 The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9. 

深度优先遍历二叉树，每次遍历返回两个值：分别表示偷窃或者不偷窃当前节点可以获得的最大收益。

状态转移方程见代码。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

  class Solution {
  public:
	  // <max use root, max not use root>
	  pair<int, int> dfs(TreeNode* root) {
		  if (root==NULL) return make_pair(0, 0);
		  auto lp=dfs(root->left);
		  auto rp=dfs(root->right);

		  return make_pair(root->val+lp.second+rp.second, max(lp.first, lp.second)+max(rp.first, rp.second));
	  }

	  int rob(TreeNode* root) {
		  pair<int, int> p=dfs(root);
		  return max(p.first, p.second);
      }
  };

int main()
{
	return 0;
}

