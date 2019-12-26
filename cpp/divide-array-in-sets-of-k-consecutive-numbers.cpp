1296. Divide Array in Sets of K Consecutive Numbers
Medium

77

3

Add to List

Share
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [3,3,2,2,1,1], k = 3
Output: true
Example 4:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length

Google
|
LeetCode

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if (n%k!=0) return false;        
        map<int, int> mp;
        for (auto& i:nums) mp[i]++;
        
        for (int i=0; i<n/k; ++i) {
            auto iter=mp.begin();
            int val=iter->first;
            for (int j=0; j<k; ++j, ++iter) {
                if (iter==mp.end() || iter->first!=val+j) return false;
                iter->second--;
                if (iter->second==0) mp.erase(iter);
            }
        }
        return true;
    }
};

