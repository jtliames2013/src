// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

// NOTE: Use BFS since the problem require from top to down

  struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    struct Element {
        TreeNode *node;
        int index;
        Element(TreeNode *n, int i) : node(n), index(i) {}
    };
    void getBound(TreeNode* root, int index) {
        if (root==NULL) return;
        l=min(l, index);
        r=max(r, index);
        getBound(root->left, index-1);
        getBound(root->right, index+1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        l=INT_MAX;
        r=INT_MIN;
        if (root==NULL) return vector<vector<int>>();

        getBound(root, 0);
        vector<vector<int>> res(r-l+1, vector<int>());

        queue<Element> q;
        q.push(Element(root, 0));
        
        while (!q.empty()) {
            Element e=q.front();
            q.pop();
            res[e.index-l].push_back(e.node->val);

            if (e.node->left!=NULL) q.push(Element(e.node->left, e.index-1));
            if (e.node->right!=NULL) q.push(Element(e.node->right, e.index+1));
        }

        return res;
    }
private:
    int l;
    int r;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
