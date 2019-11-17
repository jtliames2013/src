72. Edit Distance 
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0; i<=m; i++) dp[i][0]=i;
        for (int j=0; j<=n; j++) dp[0][j]=j;
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int delta=word1[i-1]==word2[j-1]?0:1;
                dp[i][j]=min(min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1]+delta);
            }
        }
        return dp[m][n];
    }
};

2. 1D dp array
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<int> dp(n+1, 0);
        for (int j=0; j<=n; j++) dp[j]=j;
        
        for (int i=1; i<=m; i++) {
            int prev=i-1;
            dp[0]=i;
            for (int j=1; j<=n; j++) {
                int delta=word1[i-1]==word2[j-1]?0:1;
                int tmp=dp[j];
                dp[j]=min(min(dp[j], dp[j-1])+1, prev+delta);
                prev=tmp;
            }
        }
        return dp[n];
    }
};

