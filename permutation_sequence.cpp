60. Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Hide Company Tags Twitter
Hide Tags Backtracking Math
Hide Similar Problems (M) Next Permutation (M) Permutations

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
	int factorial(int n) {
		int sum=1;
		for (int i=1; i<=n; i++) {
			sum *= i;
		}
		return sum;
	}

    string getPermutation(int n, int k) {
    	string res;
    	int pos;
    	vector<int> nums;
    	for (int i=1;i<=n;i++) {
    		nums.push_back(i);
    	}

    	k--;
    	for (int i=n-1; i>=1; i--) {
    		int f=factorial(i);
    		pos=k/f;
    		res.push_back('0'+nums[pos]);
    		nums.erase(nums.begin()+pos);
    		k=k%f;
    	}
    	res.push_back('0'+nums[0]);

    	return res;
    }
};

int main()
{
	return 0;
}


