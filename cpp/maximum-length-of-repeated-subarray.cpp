718. Maximum Length of Repeated Subarray
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

1. 2D array
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(), n=B.size();
        int res=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};

2. 1D array
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(), n=B.size();
        int res=0;
        vector<int> dp(n+1);
        for (int i=1; i<=m; i++) {            
            int prev=dp[0];
            for (int j=1; j<=n; j++) {
                int curr=dp[j];                
                dp[j]=A[i-1]==B[j-1]?prev+1:0;
                prev=curr;
                res=max(res, dp[j]);      
            }
        }
        return res;
    }
};
