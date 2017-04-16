349. Intersection of Two Arrays Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 81998
Total Submissions: 176144
Difficulty: Easy
Contributor: LeetCode
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
Subscribe to see which companies asked this question.

Hide Tags Binary Search Hash Table Two Pointers Sort
Hide Similar Problems (E) Intersection of Two Arrays II

1. Sort array
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1=nums1.size(), n2=nums2.size();
        if (n1==0 || n2==0) return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for (int i=0, j=0; i<n1 && j<n2; ) {
            if (nums1[i]<nums2[j]) i++;
            else if (nums1[i]>nums2[j]) j++;
            else {
                int val =nums1[i];
                res.push_back(val);
                while (i<n1 && nums1[i]==val) i++;
                while (j<n2 && nums2[j]==val) j++;
            }
        }
        
        return res;
    }
};

2. Use set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> st1, st2;
        for (auto n:nums1) st1.insert(n);
        for (auto n:nums2) {
            if (st1.find(n)!=st1.end()) st2.insert(n);
        }
        
        for (auto n:st2) res.push_back(n);
        return res;
    }
};

