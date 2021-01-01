1681. Minimum Incompatibility
Hard

91

75

Add to List

Share
You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.

A subset's incompatibility is the difference between the maximum and minimum elements in that array.

Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.

A subset is a group integers that appear in the array with no particular order.

 

Example 1:

Input: nums = [1,2,1,4], k = 2
Output: 4
Explanation: The optimal distribution of subsets is [1,2] and [1,4].
The incompatibility is (2-1) + (4-1) = 4.
Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.
Example 2:

Input: nums = [6,3,8,1,3,1,2,2], k = 4
Output: 6
Explanation: The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
Example 3:

Input: nums = [5,3,3,6,3,3], k = 3
Output: -1
Explanation: It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
 

Constraints:

1 <= k <= nums.length <= 16
nums.length is divisible by k
1 <= nums[i] <= nums.length

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n=nums.size(), m=n/k;
        vector<int> dp(1<<n, INT_MAX);
        dp[0]=0;
        auto values=getValues(nums, m, n);
        for (int i=0; i<(1<<n); ++i) {
            if (__builtin_popcount(i)%m!=0) continue;
            // https://cp-algorithms.com/algebra/all-submasks.html
            for (int j=i; j; j=(j-1)&i) {
                if (dp[i-j]==INT_MAX || values[j]==-1) continue;
                dp[i]=min(dp[i], dp[i-j]+values[j]);
            }
        }
        return dp.back()==INT_MAX?-1:dp.back();
    }
private:
    vector<int> getValues(vector<int>& nums, int m, int n) {
        vector<int> res(1<<n, -1);
        for (int i=0; i<(1<<n); ++i) {
            if (__builtin_popcount(i)!=m) continue;
            int mx=INT_MIN, mn=INT_MAX;
            bool dup=false;
            unordered_set<int> st;
            for (int j=0; j<n; ++j) {
                if ((i & (1<<j))==0) continue;
                if (st.find(nums[j])!=st.end()) {
                    dup=true;
                    break;
                }
                st.insert(nums[j]);
                mx=max(mx, nums[j]);
                mn=min(mn, nums[j]);
            }
            if (dup) continue;
            
            res[i]=mx-mn;
        }
        return res;
    }
};
