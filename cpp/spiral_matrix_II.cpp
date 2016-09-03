59. Spiral Matrix II  QuestionEditorial Solution  My Submissions
Total Accepted: 56680
Total Submissions: 158341
Difficulty: Medium
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
Hide Tags Array
Hide Similar Problems (M) Spiral Matrix

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
    vector<vector<int>> generateMatrix(int n) {
    	if (n==0) {
    		vector<vector<int> > res;
    		return res;
    	}

    	vector<vector<int> > res(n, vector<int>(n));
    	int num=1;
    	for (int i=0; i<n/2; i++) {
    		for (int j=i; j<n-i; j++) {
    			res[i][j] = num++;
    		}
    		for (int j=i+1; j<n-i; j++) {
    			res[j][n-1-i] = num++;
    		}
    		for (int j=n-2-i; j>=i; j--) {
    			res[n-1-i][j] = num++;
    		}
    		for (int j=n-2-i; j>=i+1; j--) {
    			res[j][i] = num++;
    		}
    	}

    	if (n%2 == 1) {
    	  	res[n/2][n/2] = num;
    	}

    	return res;
    }
};


2.
class Solution {

public:

    vector<vector<int>> generateMatrix(int n) {

        if (n==0) return vector<vector<int>>();

        vector<vector<int>> res(n, vector<int>(n, 0));

        int num=1;

        for (int i=0; i<(n+1)/2; i++) {

            // top

            for (int j=i; j<n-i; j++) {

                res[i][j]=num++;

            }

            // right

            for (int j=i+1; j<n-i; j++) {

                res[j][n-i-1]=num++;

            }

            // bottom

            for (int j=n-i-2; j>=i; j--) {

                res[n-i-1][j]=num++;

            }

            // left

            for (int j=n-i-2; j>i; j--) {

                res[j][i]=num++;

            }

        }

        

        return res;

    }

};


int main()
{
	return 0;
}

