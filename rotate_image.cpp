#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
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
    void rotate(vector<vector<int>>& matrix) {
    	if (matrix.size()==0) return;

    	int n=matrix.size();

    	for (int i=0; i<n/2; i++) {
    		for (int j=i; j<n-1-i; j++) {
    			int tmp=matrix[i][j];
    			matrix[i][j]=matrix[n-1-j][i];
    			matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
    			matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
    			matrix[j][n-1-i]=tmp;
    		}
    	}
    }
};

int main()
{
	return 0;
}

