97. Interleaving String
DescriptionHintsSubmissionsSolutions
Total Accepted: 68670
Total Submissions: 281949
Difficulty: Hard
Contributor: LeetCode
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming String

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if (n1+n2!=n3) return false;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
        for (int i=0; i<=n1; i++) {
            for (int j=0; j<=n2; j++) {
                if (i==0 && j==0) dp[i][j]=true;
                else {
                    if (i>0) dp[i][j]=(dp[i][j] || (dp[i-1][j] && s3[i+j-1]==s1[i-1]));
                    if (j>0) dp[i][j]=(dp[i][j] || (dp[i][j-1] && s3[i+j-1]==s2[j-1]));
                }
            }
        }
        
        return dp[n1][n2];
    }
};

