576. Out of Boundary Paths Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 1799
Total Submissions: 5434
Difficulty: Hard
Contributors:
fallcreek
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Depth-first Search

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n));
        while (N-- > 0) {
            vector<vector<unsigned int>> next(m, vector<unsigned int>(n));
            for (int k=0; k<m; ++k) {
                for (int l=0; l<n; ++l) {
                    for (int d=0; d<4; ++d) {
                        int nr=k+delta[d][0];
                        int nc=l+delta[d][1];
                        if (nr>=0 && nr<m && nc>=0 && nc<n) next[k][l]+=dp[nr][nc];
                        else next[k][l]+=1;
                    }
                    next[k][l]%=mod;
                }
            }
            dp=next;
        }
        return dp[i][j];
    }
private:
    const int mod=1e9+7;
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
