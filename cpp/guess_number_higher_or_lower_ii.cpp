375. Guess Number Higher or Lower II   QuestionEditorial Solution  My Submissions
Total Accepted: 9978 Total Submissions: 30107 Difficulty: Medium Contributors: Admin
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Hint:

The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
Take a small example (n = 3). What do you end up paying in the worst case?
Check out this article if you're still stuck.
The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.
Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Flip Game II (E) Guess Number Higher or Lower

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n<=1) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len=1; len<n; len++) {
            for (int left=0, right=left+len; right<n; left++, right++) {
                dp[left][right]=INT_MAX;
                for (int k=left; k<=right; k++) {
                    int l=k==left?0:dp[left][k-1];
                    int r=k==right?0:dp[k+1][right];
                    dp[left][right]=min(dp[left][right], k+1+max(l, r));
                }
            }
        }
        
        return dp[0][n-1];
    }
};

