42. Trapping Rain Water  QuestionEditorial Solution  My Submissions
Total Accepted: 72624 Total Submissions: 219642 Difficulty: Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

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
    int trap(vector<int>& height) {
    	int size=height.size();
    	if (size<3) return 0;

    	vector<int> leftMax(size, 0);
    	vector<int> rightMax(size, 0);
    	int volume=0;

    	for (int i=1; i<size; i++) {
    		leftMax[i] = max(leftMax[i-1], height[i-1]);
    	}

    	for (int i=size-2; i>=0; i--) {
    		rightMax[i] = max(rightMax[i+1], height[i+1]);
    		int depth = min(leftMax[i], rightMax[i]) - height[i];
    		if (depth>0) {
    			volume += depth;
    		}
    	}

    	return volume;
    }
};

int main()
{
	return 0;
}

