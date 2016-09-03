169. Majority Element  
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Adobe Zenefits
Hide Tags Array Divide and Conquer Bit Manipulation
Hide Similar Problems (M) Majority Element II

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
    int majorityElement(vector<int>& nums) {
    	map<int, int> counts;
    	int size=nums.size();
    	for (int i=0; i<nums.size(); i++) {
    		auto it=counts.find(nums[i]);
    		if (it==counts.end()) {
    			counts.insert(make_pair(nums[i], 1));
    		} else {
    			(*it).second++;
    		}
    	}

    	for (auto it=counts.begin(); it!=counts.end(); it++) {
    		if ((*it).second > size/2) return (*it).first;
    	}

    	return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int, int> count;
        for (auto num:nums) count[num]++;
        
        for (auto c:count) {
            if (c.second>n/2) return c.first;
        }
        return 0;
    }
};

int main()
{
	return 0;
}

