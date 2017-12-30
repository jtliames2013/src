741. Cherry Pickup
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
Example 1:
Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        // the most number of cherries obtained by two people
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0]=grid[0][0];
        
        for (int t=1; t<=2*n-2; t++) {
            // each move step from top-left to bottom-right
            vector<vector<int>> next(n, vector<int>(n, INT_MIN));
            for (int i=max(0, t-(n-1)); i<=min(n-1, t); i++) {
                // number of steps down for person 1
                for (int j=max(0, t-(n-1)); j<=min(n-1, t); j++) {
                    // number of steps down for person 2
                    if (grid[i][t-i]==-1 || grid[j][t-j]==-1) continue;
                    int val=grid[i][t-i];
                    if (i!=j) val+=grid[j][t-j];
                    for (int k=i-1; k<=i; k++) {
                        for (int l=j-1; l<=j; l++) {
                            if (k>=0 && l>=0) next[i][j]=max(next[i][j], dp[k][l]+val);
                        }
                    }
                }
            }
            dp=next;
        }
        return max(0,dp[n-1][n-1]);
    }
};
