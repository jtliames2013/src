562. Longest Line of Consecutive One in Matrix
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.

Google
|
2

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m=M.size();
        if (m==0) return 0;
        int n=M[0].size();
        if (n==0) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (M[i][j]==0) continue;
                for (int k=0; k<4; k++) dp[i][j][k]=1;
                if (i>0) dp[i][j][0]+=dp[i-1][j][0];
                if (j>0) dp[i][j][1]+=dp[i][j-1][1];
                if (i>0 && j>0) dp[i][j][2]+=dp[i-1][j-1][2];
                if (i>0 && j<n-1) dp[i][j][3]+=dp[i-1][j+1][3];
                res=max(res, max(dp[i][j][0], dp[i][j][1]));
                res=max(res, max(dp[i][j][2], dp[i][j][3]));
            }
        }
        
        
        return res;
    }
};

