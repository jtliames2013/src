486. Predict the Winner Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8911
Total Submissions: 20020
Difficulty: Medium
Contributors:
sameer13
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Minimax
Hide Similar Problems (M) Can I Win

1. Recursively
class Solution {
public:
    int dfs(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
        if (dp[l][r]==INT_MIN) {
            dp[l][r] = l==r?nums[l]:max(nums[l]-dfs(nums, dp, l+1, r), nums[r]-dfs(nums, dp, l, r-1));
        }
        return dp[l][r];  
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return dfs(nums, dp, 0, n-1)>=0;
    }
};

2. DP
Update diagonally
1 2 3
  1 2
    1
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l=1; l<=n; l++) {
            for (int i=0; i+l<=n; i++) {
                dp[i][i+l-1]=l==1?nums[i]:max(nums[i]-dp[i+1][i+l-1], nums[i+l-1]-dp[i][i+l-2]);
            }
        }
        
        return dp[0][n-1]>=0;
    }
};

3. 1D DP
Update from bottom
3 3 3
  2 2
    1
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                dp[j]=j==i?nums[i]:max(nums[j]-dp[j-1], nums[i]-dp[j]);
            }
        }
        
        return dp[n-1]>=0;
    }
};

