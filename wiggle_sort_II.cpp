解法I O(nlogn)时间排序+O(n)空间辅助数组解法：

1. 对原数组排序，得到排序后的辅助数组snums

2. 对原数组的偶数位下标填充snums的末尾元素

3. 对原数组的奇数位下标填充snums的末尾元素

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
    void wiggleSort(vector<int>& nums) {
    	if (nums.size()==0) return;
    	vector<int> sorted(nums.size());
    	for (int i=0; i<sorted.size(); i++) {
    		sorted[i]=nums[i];
    	}
    	sort(sorted.begin(), sorted.end());

    	int j=sorted.size()-1;
    	for (int i=1; i<nums.size(); i+=2) {
    		nums[i]=sorted[j];
    		j--;
    	}
    	for (int i=0; i<nums.size(); i+=2) {
    		nums[i]=sorted[j];
    		j--;
    	}
    }
};

int main()
{
	return 0;
}

