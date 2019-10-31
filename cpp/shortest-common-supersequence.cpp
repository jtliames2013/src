1092. Shortest Common Supersequence
Hard

202

6

Favorite

Share
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string res;
        int i=0, j=0;
        for (auto c:longestCommonSubsequence(str1, str2)) {
            while (str1[i]!=c) res+=str1[i++];
            while (str2[j]!=c) res+=str2[j++];            
            res+=c;
            i++;
            j++;
        }
        
        res+=str1.substr(i)+str2.substr(j);
        return res;
    }
private:
    string longestCommonSubsequence(string& a, string& b) {
        int m=a.size(), n=b.size();
        vector<vector<string>> dp(m+1, vector<string>(n+1, ""));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+a[i-1];
                else dp[i][j]=dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
