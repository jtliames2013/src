698. Partition to K Equal Sum Subsets
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

class Solution {
public:
    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int start, int target, int currSum, int currNum) {
        if (k==1) return true;
        if (currSum==target && currNum>0) return dfs(nums, visited, k-1, 0, target, 0, 0);
        for (int i=start; i<nums.size(); i++) {
            if (visited[i]==false) {
                visited[i]=true;
                if (dfs(nums, visited, k, i+1, target, currSum+nums[i], currNum+1)) return true;
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for (auto n:nums) sum+=n;
        if (k<=0 || sum%k!=0) return false;
        vector<bool> visited(nums.size());
        return dfs(nums, visited, k, 0, sum/k, 0, 0);
    }
};

