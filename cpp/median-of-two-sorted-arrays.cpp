4. Median of Two Sorted Arrays
DescriptionHintsSubmissionsSolutions
Total Accepted: 167896
Total Submissions: 783946
Difficulty: Hard
Contributor: LeetCode
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
Subscribe to see which companies asked this question.

Hide Tags Binary Search Array Divide and Conquer

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

