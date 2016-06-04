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
#include <math.h>

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
	int min(int a, int b, int c) {
		if (a>b) return b>c ? c : b;
		else return a>c ? c : a;
	}

    int maximalSquare(vector<vector<char>>& matrix) {
    	int row=matrix.size();
    	if (row==0) return 0;
    	int col=matrix[0].size();
    	if (col==0) return 0;

    	vector<vector<int> > res(row, vector<int>(col));
    	int max=0;
    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++)
    			res[i][j]=0;
    	}

    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			res[i][j]=matrix[i][j]-'0';

    			if (res[i][j]==1 && i>0 && j>0) {
    				res[i][j]=min(res[i-1][j], res[i][j-1], res[i-1][j-1])+1;
    			}

    			if (max < res[i][j]) max=res[i][j];
    		}
    	}

    	return max*max;
    }
};

int main()
{
	return 0;
}

