221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Hide Company Tags Apple Airbnb Facebook
Hide Tags Dynamic Programming
Hide Similar Problems (H) Maximal Rectangle

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int maxLen=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j]=min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                }
                maxLen=max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen*maxLen;
    }
};

