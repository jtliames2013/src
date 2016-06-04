You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Note: for boundary condition, allocate one more than nums size.

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
    int rob(vector<int>& nums) {
    	int size=nums.size();
    	if (size==0) return 0;
    	vector<int> res(size);

    	for (int i=0; i<size; i++) {
    		if (i==0) {
    			res[i]=nums[i];
    		} else if (i==1) {
    			res[i]=max(nums[i], nums[i-1]);
    		} else {
    			res[i]=max(res[i-1], res[i-2]+nums[i]);
    		}
    	}

    	return res[size-1];
    }
};

==========================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if (size==0) return 0;
        vector<int> dp(size+1, 0);
        dp[1]=nums[0];
        for (int i=2; i<=size; i++) {
            dp[i]=max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        
        return dp[size];
    }
};

==================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if (size==0) return 0;
        int odd=0, even=0;
        
        for (int i=0; i<nums.size(); i++) {
            if (i%2==1) odd=max(even, odd+nums[i]);
            else even=max(odd, even+nums[i]);
        }
        
        return max(odd, even);
    }
};


int main()
{
	return 0;
}


