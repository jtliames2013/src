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
    void setZeroes(vector<vector<int>>& matrix) {
    	int row=matrix.size();
    	if (row==0) return;
    	int col=matrix[0].size();
    	if (col==0) return;

    	bool firstRow=false, firstCol=false;
    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			if (matrix[i][j]==0) {
    				if (i==0) firstRow=true;
    				if (j==0) firstCol=true;
    				matrix[0][j]=matrix[i][0]=0;
    			}
    		}
    	}

    	for (int i=1; i<row; i++) {
    		if (matrix[i][0]==0) {
    			for (int j=0; j<col; j++) matrix[i][j]=0;
    		}
    	}

    	for (int j=1; j<col; j++) {
    		if (matrix[0][j]==0) {
    			for (int i=0; i<row; i++) matrix[i][j]=0;
    		}
    	}

    	if (firstRow==true) {
    		for (int j=0; j<col; j++) matrix[0][j]=0;
    	}

    	if (firstCol==true) {
    		for (int i=0; i<row; i++) matrix[i][0]=0;
    	}
    }
};

int main()
{
	return 0;
}

