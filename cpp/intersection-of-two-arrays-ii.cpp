350. Intersection of Two Arrays II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 59586
Total Submissions: 134834
Difficulty: Easy
Contributor: LeetCode
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Subscribe to see which companies asked this question.

Hide Tags Binary Search Hash Table Two Pointers Sort
Hide Similar Problems (E) Intersection of Two Arrays

1. Sort array
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1=nums1.size(), n2=nums2.size();
        if (n1==0 || n2==0) return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for (int i1=0, i2=0; i1<n1 && i2<n2; ) {
            if (nums1[i1]<nums2[i2]) i1++;
            else if (nums1[i1]>nums2[i2]) i2++;
            else {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }
        return res;
    }
};

2. Use map
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1=nums1.size(), n2=nums2.size();
        if (n1==0 || n2==0) return res;
        if (n1>n2) return intersect(nums2, nums1);
        
        unordered_map<int,int> mp;
        for (auto n:nums1) mp[n]++;
        for (auto n:nums2) {
            if (mp[n]>0) {
                res.push_back(n);
                mp[n]--;
            }
        }
        
        return res;
    }
};

