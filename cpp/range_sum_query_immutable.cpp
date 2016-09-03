303. Range Sum Query - Immutable  QuestionEditorial Solution  My Submissions
Total Accepted: 39752 Total Submissions: 154898 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Hide Company Tags Palantir
Hide Tags Dynamic Programming
Hide Similar Problems (M) Range Sum Query 2D - Immutable (M) Range Sum Query - Mutable (M) Maximum Size Subarray Sum Equals k

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

class NumArray {
public:
	vector<int> sum;

    NumArray(vector<int> &nums) {
    	int size=nums.size();
    	if (size>0) {
    		sum.push_back(nums[0]);
			for (int i=1; i<size; i++) {
				int num=sum.back();
				sum.push_back(nums[i]+num);
			}
    	}
    }

    int sumRange(int i, int j) {
    	int substract=0;
    	if (i>0) substract=sum[i-1];
    	return sum[j]-substract;
    }
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n=nums.size();
        sums.resize(n+1, 0);
        for (int i=1; i<=n; i++) {
            sums[i]=sums[i-1]+nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
private:
    vector<int> sums;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
	return 0;
}

