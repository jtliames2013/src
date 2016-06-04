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

int main()
{
	return 0;
}

