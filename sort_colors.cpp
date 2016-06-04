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
	void swap(vector<int>& nums, int i, int j)
	{
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}

    void sortColors(vector<int>& nums) {
    	if (nums.size()==0) return;
    	int begin=0, end=nums.size()-1;
    	int i=0;

    	while (i<=end)
    	{
    		if (nums[i]==0)
    		{
    			swap(nums, i, begin);
    			i++;
    			begin++;
    		}
    		else if(nums[i]==2)
    		{
    			swap(nums, i, end);
    			end--;
    		}
    		else
    		{
    			i++;
    		}
    	}
    }
};

int main()
{
	return 0;
}

