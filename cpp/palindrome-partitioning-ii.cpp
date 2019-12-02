132. Palindrome Partitioning II  QuestionEditorial Solution  My Submissions
Total Accepted: 55383 Total Submissions: 245684 Difficulty: Hard
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Hide Tags Dynamic Programming
Hide Similar Problems (M) Palindrome Partitioning

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<int> dp(n+1, INT_MAX);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if (i==j) isPalin[i][j]=true;
                else if (j==i+1) isPalin[i][j]=s[i]==s[j];
                else isPalin[i][j]=(s[i]==s[j]&&isPalin[i+1][j-1]);
            }
        }
        
    	// if it is palindrome from begining, cut is 0        
        dp[0]=-1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (isPalin[j][i-1]) {
                    dp[i]=min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};

