96. Unique Binary Search Trees Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 114993
Total Submissions: 285161
Difficulty: Medium
Contributor: LeetCode
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Subscribe to see which companies asked this question.

Hide Tags Tree Dynamic Programming
Hide Similar Problems (M) Unique Binary Search Trees II

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
    }
};

