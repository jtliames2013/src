1444. Number of Ways of Cutting a Pizza
Hard

29

3

Add to List

Share
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
Example 2:

Input: pizza = ["A..","AA.","..."], k = 3
Output: 1
Example 3:

Input: pizza = ["A..","A..","..."], k = 1
Output: 1
 

Constraints:

1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza consists of characters 'A' and '.' only.

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size(), n=pizza[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        vector<vector<int>> sums(m+1, vector<int>(n+1));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+(pizza[i-1][j-1]=='A'?1:0);
            }
        }
        return dfs(sums, dp, 0, 0, m, n, k);
    }

private:
    int dfs(vector<vector<int>>& sums, vector<vector<vector<int>>>& dp, int row, int col, int m, int n, int k) {
        if (k==1) {
            dp[row][col][k]=getSum(sums, row, col, m-1, n-1)>0?1:0;;
            return dp[row][col][k];
        }
        if (dp[row][col][k]>=0) return dp[row][col][k];

        int res=0;
        for (int i=row+1; i<m; ++i) {
            if (getSum(sums, row, col, i-1, n-1)==0) continue;
            res=(res+dfs(sums, dp, i, col, m, n, k-1))%mod;
        }

        for (int j=col+1; j<n; ++j) {
            if (getSum(sums, row, col, m-1, j-1)==0) continue;
            res=(res+dfs(sums, dp, row, j, m, n, k-1))%mod;
        }

        dp[row][col][k]=res;
        return res;
    }

    int getSum(vector<vector<int>>& sums, int r1, int c1, int r2, int c2) {
        return sums[r2+1][c2+1]-sums[r1][c2+1]-sums[r2+1][c1]+sums[r1][c1];
    }

    const int mod=1e9+7;
};

