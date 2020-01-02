1301. Number of Paths with Max Score
Hard

44

2

Add to List

Share
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100

Samsung
|
LeetCode

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> dpSum(m, vector<int>(n)), dpCnt(m, vector<int>(n));
        dpCnt[m-1][n-1]=1;
        for (int row=m-1; row>=0; --row) {
            for (int col=n-1; col>=0; --col) {
                if (dpCnt[row][col]==0) continue;
                for (int k=0; k<3; ++k) {
                    int nr=row+delta[k][0];
                    int nc=col+delta[k][1];
                    if (nr>=0 && nc>=0 && board[nr][nc]!='X') {
                        int sum=dpSum[row][col];
                        if (board[nr][nc]!='E') sum+=board[nr][nc]-'0';
                        if (sum>dpSum[nr][nc]) {
                            dpSum[nr][nc]=sum;
                            dpCnt[nr][nc]=dpCnt[row][col];
                        } else if (sum==dpSum[nr][nc]) {
                            dpCnt[nr][nc]=(dpCnt[nr][nc]+dpCnt[row][col])%mod;
                        }
                    }
                }
            }
        }
        
        return {dpSum[0][0], dpCnt[0][0]};
    }
private:
    const int mod=1e9+7;
    const int delta[3][2]={{-1, 0}, {0, -1}, {-1, -1}};
};

