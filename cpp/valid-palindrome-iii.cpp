1216. Valid Palindrome III
Hard

87

3

Add to List

Share
Given a string s and an integer k, find out if the given string is a K-Palindrome or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
 

Constraints:

1 <= s.length <= 1000
s has only lowercase English letters.
1 <= k <= s.length

Facebook
|
3

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l=1; l<=n; ++l) {
            for (int i=0; i<=n-l; ++i) {
                if (l==1) dp[i][i+l-1]=1;
                else {
                    dp[i][i+l-1]=s[i]==s[i+l-1]?dp[i+1][i+l-2]+2:max(dp[i+1][i+l-1], dp[i][i+l-2]);
                }
            }
        }
        
        return n-dp[0][n-1]<=k;
    }
};

