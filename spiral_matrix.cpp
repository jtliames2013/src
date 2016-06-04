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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
    	int m=matrix.size();
    	if (m==0) return res;
    	int n=matrix[0].size();
    	int size=m>n ? n : m;

    	for (int i=0; i<size/2; i++) {
    		for (int j=i; j<n-i; j++) {
    			res.push_back(matrix[i][j]);
    		}
    		for (int j=i+1; j<m-i; j++) {
    			res.push_back(matrix[j][n-i-1]);
    		}
    		for (int j=n-i-2; j>=i; j--) {
    			res.push_back(matrix[m-i-1][j]);
    		}
    		for (int j=m-i-2; j>i; j--) {
    			res.push_back(matrix[j][i]);
    		}
    	}

    	if (size % 2 == 1) {
    		if (m>n) {
    			for (int i=size/2; i<m-size/2; i++) {
    				res.push_back(matrix[i][size/2]);
    			}
    		} else {
    			for (int i=size/2; i<n-size/2; i++) {
    				res.push_back(matrix[size/2][i]);
    			}
    		}
    	}

    	return res;
    }
};

2.
class Solution {

public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        int m=matrix.size();

        if (m==0) return res;

        int n=matrix[0].size();

        if (n==0) return res;

        

        int i=0, j=0;

        for (int i=0, j=0; i<(m+1)/2 && j<(n+1)/2; i++, j++) {

            // top

            for (int k=j; k<n-j; k++) {

                res.push_back(matrix[i][k]);

            }

            // right

            for (int k=i+1; k<m-i; k++) {

                res.push_back(matrix[k][n-j-1]);

            }

            // bottom

            if (i<m-i-1) {

                for (int k=n-j-2; k>=j; k--) {

                    res.push_back(matrix[m-i-1][k]);

                }

            }

            // left

            if (j<n-j-1) {

                for (int k=m-i-2; k>i; k--) {

                    res.push_back(matrix[k][j]);

                }

            }

        }

        

        return res;

    }

};

int main()
{
	return 0;
}


