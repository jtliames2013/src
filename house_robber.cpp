198. House Robber  
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Hide Company Tags LinkedIn Airbnb
Hide Tags Dynamic Programming
Hide Similar Problems (M) Maximum Product Subarray (M) House Robber II (M) Paint House (E) Paint Fence (M) House Robber III

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

3. get the list of houses
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<vector<int>> select(n+1);
        vector<int> dp(n+1, 0);
        dp[1]=nums[0];
        select[1].push_back({0});
        for (int i=2; i<=n; i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
            if (dp[i-1]<dp[i-2]+nums[i-1]) {
                select[i]=select[i-2];
                select[i].push_back(i-1);
            } else {
                select[i]=select[i-1];
            }
        }
        
        for (auto s:select[n]) cout << s << " ";
        cout << endl;
        return dp[n];
    }
};


int main()
{
	return 0;
}


