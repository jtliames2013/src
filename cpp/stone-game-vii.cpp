1690. Stone Game VII
Medium

146

62

Add to List

Share
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
Example 2:

Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
 

Constraints:

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000

suppose n=5, then Alice's gain is a1+a3+a5 where a1 means the 1st round's gain for Alice. 
Bob's gain is b2+b4. The final difference is (a1+a3+a5)-(b2+b4) which can be rewritten as a1-(b2-(a3-(b4-a5))). 
If we realize that a1>b2>a3>b4>a5, we know this is actually a recursive pattern. 
The optimal strategy for both players is to maximize my_current_round_gain - subproblem_difference. 
Alice wants to maximize a1-subproblem, so Alice wants to maximize a3-subproblem due to the double negation. 
The same for Bob. Bob wants to minimize a1-subproblem, so Bob wants to maximize b2-subproblem,
then maximize b4-subproblem due to double negation.

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(1000, vector<int>(1000));
        return dfs(0, n-1, dp, stones, accumulate(stones.begin(), stones.end(), 0));
    }
private:
    int dfs(int l, int r, vector<vector<int>>& dp, vector<int>& stones, int sum) {
        if (l==r) return 0;
        if (dp[l][r]>0) return dp[l][r];
        dp[l][r]=max(sum-stones[l]-dfs(l+1, r, dp, stones, sum-stones[l]), sum-stones[r]-dfs(l, r-1, dp, stones, sum-stones[r]));
        return dp[l][r];
    }
};
