1703. Minimum Adjacent Swaps for K Consecutive Ones
Hard

104

4

Add to List

Share
You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.

Return the minimum number of moves required so that nums has k consecutive 1's.

 

Example 1:

Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
Example 2:

Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
Example 3:

Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.
 

Constraints:

1 <= nums.length <= 105
nums[i] is 0 or 1.
1 <= k <= sum(nums)

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        long res=INT_MAX;
        vector<int> ones;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]==1) ones.push_back(i);
        }
        int n=ones.size();
        vector<long> sums(n+1);
        for (int i=1; i<=n; ++i) sums[i]=sums[i-1]+ones[i-1];
        
        for (int i=0; i<n-k+1; ++i) {
            res=min(res, sums[i+k]-sums[i+(k+1)/2]-sums[i+k/2]+sums[i]);
        }
        
        // odd: (1+2+...+k/2)*2 = (k/2)*(k/2+1)
        // even: (1+2+...+k/2-1)*2 + k/2 = (k/2)*(k/2)
        return res-(k/2)*((k+1)/2);
    }
};

