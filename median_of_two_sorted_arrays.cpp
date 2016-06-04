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
	int findKthElement(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k) {
		if (s1>e1) return nums2[s2+k];
		if (s2>e2) return nums1[s1+k];

		int m1=(s1+e1)/2;
		int m2=(s2+e2)/2;
		if (nums1[m1]>nums2[m2]) {
			if (k>(m1-s1+m2-s2)) {
				return findKthElement(nums1, s1, e1, nums2, m2+1, e2, k-(m2-s2)-1);
			} else {
				return findKthElement(nums1, s1, m1-1, nums2, s2, e2, k);
			}
		} else {
			if (k>(m1-s1+m2-s2)) {
				return findKthElement(nums1, m1+1, e1, nums2, s2, e2, k-(m1-s1)-1);
			} else {
				return findKthElement(nums1, s1, e1, nums2, s2, m2-1, k);
			}
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size1=nums1.size();
    	int size2=nums2.size();
    	int m=(size1+size2)/2;

    	if ((size1+size2)%2==0) {
    		double m1 = findKthElement(nums1, 0, size1-1, nums2, 0, size2-1, m-1);
    		double m2 = findKthElement(nums1, 0, size1-1, nums2, 0, size2-1, m);
    		return 0.5 * (m1+m2);
    	} else {
    		return findKthElement(nums1, 0, size1-1, nums2, 0, size2-1, m);
    	}
    }
};

int main()
{
	Solution s;
	vector<int> v1(2); v1[0]=v1[1]=1;
	vector<int> v2(2); v2[0]=v2[1]=1;

	double d=s.findMedianSortedArrays(v1, v2);
	return 0;
}

