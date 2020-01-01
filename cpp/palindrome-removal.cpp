1246. Palindrome Removal
Hard

78

0

Add to List

Share
Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.

 

Example 1:

Input: arr = [1,2]
Output: 2
Example 2:

Input: arr = [1,3,4,1,5]
Output: 3
Explanation: Remove [4] then remove [1,3,1] then remove [5].
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 20

Microsoft
|
LeetCode

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i=0; i<n; ++i) dp[i][i]=1;
        for (int i=0; i<n-1; ++i) dp[i][i+1]=arr[i]==arr[i+1]?1:2;
        for (int len=3; len<=n; ++len) {
            for (int i=0, j=len-1; i+len<=n; ++i, ++j) {
                if (arr[i]==arr[j]) dp[i][j]=dp[i+1][j-1];
                for (int k=i; k<j; ++k) {
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};

