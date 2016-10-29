#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <limits.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> res;
        if (l>=r) {
            res.push_back(l==r?new TreeNode(l):NULL);
            return res;
        }
        for (int i=l; i<=r; i++) {
            vector<TreeNode*> left=generateTrees(l, i-1);
            vector<TreeNode*> right=generateTrees(i+1, r);
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode *n=new TreeNode(i);
                    n->left=left[j];
                    n->right=right[k];
                    res.push_back(n);
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};

int main()
{
	return 0;
}

