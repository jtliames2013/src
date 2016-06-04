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
	int min(int a, int b) {
		return a<b ? a : b;
	}

    int maxArea(vector<int>& height) {
    	if (height.size()==0) return 0;
    	int maxarea=0;
    	int area=0;
    	int left=0, right=height.size()-1;

    	while (left <= right) {
    		area = min(height[left], height[right]) * (right-left);
    		if (area>maxarea) maxarea=area;

    		if (height[left] < height[right]) {
    			left++;
    		} else if (height[left] > height[right]) {
    			right--;
    		} else {
    			left++; right--;
    		}
    	}

    	return maxarea;
    }
};

int main()
{
	return 0;
}

