719. Find K-th Smallest Pair Distance
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int res=0;
        for (int i=0; i<nums.size(); i++) {
            auto iter=upper_bound(nums.begin(), nums.end(), nums[i]+mid);
            res+=iter-nums.begin()-1-i;
        }
        return res;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        int low=INT_MAX;
        for (int i=1; i<n; i++) low=min(low, nums[i]-nums[i-1]);
        int high=nums[n-1]-nums[0];
        while (low<high) {
            int mid=low+(high-low)/2;
            if (countPairs(nums, mid)<k) {
                low=mid+1;
            } else {
                high=mid;
            }
        }
        return low;
    }
};

