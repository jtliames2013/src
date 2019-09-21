1043. Partition Array for Maximum Sum
Medium

277

30

Favorite

Share
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]
 

Note:

1 <= K <= A.length <= 500
0 <= A[i] <= 10^6

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n=A.size();
        vector<int> dp(n);
        for (int i=0; i<n; ++i) {
            int mx=0;
            for (int len=1; len<=K && i-len+1>=0; ++len) {
                mx=max(mx, A[i-len+1]);
                dp[i]=max(dp[i], (i>=len?dp[i-len]:0)+mx*len);
            }
        }
        return dp[n-1];
    }
};
