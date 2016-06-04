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

class NumMatrix {
public:
	vector<vector<int> > sum;
    NumMatrix(vector<vector<int>> &matrix) {
    	int row=matrix.size();
    	int col;
    	if (row>0) {
    		col=matrix[0].size();
    	}

    	if (col>0) {
    		for (int i=0; i<row; i++) {
    			vector<int> v(col);
    			for (int j=0; j<col; j++) v[j]=0;
    			sum.push_back(v);
    		}
    	}

    	for (int i=0; i<row; i++) {
    		for (int j=0; j<col; j++) {
    			if (i==0 && j==0) {
    				sum[i][j]=matrix[i][j];
    			} else if (i==0) {
    				sum[i][j]=sum[i][j-1]+matrix[i][j];
    			} else if (j==0) {
    				sum[i][j]=sum[i-1][j]+matrix[i][j];
    			} else {
    				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
    			}
    		}
    	}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    	int sum1 = (row1>0? sum[row1-1][col2]:0);
    	int sum2 = (col1>0? sum[row2][col1-1]:0);
    	int sum3 = ((row1>0 && col1>0) ? sum[row1-1][col1-1]:0);

    	return sum[row2][col2]-sum1-sum2+sum3;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main()
{
	return 0;
}

