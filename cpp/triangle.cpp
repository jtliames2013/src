120. Triangle  QuestionEditorial Solution  My Submissions
Total Accepted: 76992 Total Submissions: 247542 Difficulty: Medium
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Show Tags
Have you met this question in a real interview? Yes  No

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if (n==0) return 0;
        vector<int> minsum(n+1, 0);
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                minsum[j]=triangle[i][j]+min(minsum[j],minsum[j+1]);
            }
        }
        
        return minsum[0];
    }
};
Custom Testcase    
Run Code  Submit Solution
Shortcut: Ctrl + enter
Submission Result: Accepted  More Details 

Next challenges: (E) Plus One  (E) Contains Duplicate  (M) Maximal Square
Share your acceptance!

AddThis Sharing Buttons
Frequently Asked Questions | Terms of Service



Copyright © 2016 LeetCode


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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

Note: DP, bottom up, one array for the row.

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int size = triangle.size();
    	if (size==0) return 0;

    	vector<int> min(size+1);
    	for (int i=0; i<=size; i++) min[i]=0;

    	for (int i=size-1; i>=0; i--)
    	{
    		int col=triangle[i].size();

    		for (int j=0; j<col; j++)
    		{
    			min[j] = min[j] > min[j+1] ? triangle[i][j]+min[j+1] : triangle[i][j]+min[j];
       		}
    	}

    	return min[0];
    }
};

2.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        vector<int> minsum(rows+1, 0);
        
        for (int i=rows-1; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                minsum[j]=triangle[i][j]+min(minsum[j],minsum[j+1]);
            }
        }
        
        return minsum[0];
    }

};

int main()
{
	return 0;
}

