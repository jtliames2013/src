782. Transform to Chessboard
DescriptionHintsSubmissionsDiscussSolution
An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

Examples:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation:
One potential sequence of moves is shown below, from left to right:

0110     1010     1010
0110 --> 1010 --> 0101
1001     0101     1010
1001     0101     0101

The first move swaps the first and second column.
The second move swaps the second and third row.


Input: board = [[0, 1], [1, 0]]
Output: 0
Explanation:
Also note that the board with 0 in the top left corner,
01
10

is also a valid chessboard.

Input: board = [[1, 0], [1, 0]]
Output: -1
Explanation:
No matter what sequence of moves you make, you cannot end with a valid chessboard.
Note:

board will have the same number of rows and columns, a number in the range [2, 30].
board[i][j] will be only 0s or 1s.

An observation is that, in a valid ChessBoard, any rectangle inside the board with corner NW, NE, SW, SE (NW here means north-west) must satisfy (NW xor NE) == (SW xor SE), where xor is exclusive or. Here we call it validness property.

Since the swap process does not break this property, for a given board to be valid, this property must hold. A corollary is that given a row, any other row must be identical to it or be its inverse. For example if there is a row 01010011 in the board, any other row must be either 01010011 or 10101100.

With this observation, we only need to consider the first column when we’re swapping rows to match the ChessBoard condition. That is, it suffies to find the minimum row swap to make the first column be 010101...^T or 101010...^T. (here ^T means transpose.)

Similarly, it suffies to consider the first row when swapping columns.

Now the problem becomes solvable, with the following steps:

Check if the given board satisfy the validness property defined above.
Find minimum row swap to make the first column valid. If not possible, return -1.
Find minimum column swap to make the first row valid. If not possible, return -1.
Return the sum of step 2 and 3.

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size(), rowSum=0, colSum=0, rowSwap=0, colSwap=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if ((board[0][0]^board[0][j])!=(board[i][0]^board[i][j])) return -1;
            }
        }
        
        for (int i=0; i<n; i++) {
            rowSum+=board[0][i];
            colSum+=board[i][0];
            rowSwap+=(board[i][0]==i%2);
            colSwap+=(board[0][i]==i%2);
        }
        
        if (rowSum<n/2 || rowSum>(n+1)/2) return -1;
        if (colSum<n/2 || colSum>(n+1)/2) return -1;
        if (n%2==1) {
            if (rowSwap%2==1) rowSwap=n-rowSwap;
            if (colSwap%2==1) colSwap=n-colSwap;
        } else {
            rowSwap=min(rowSwap, n-rowSwap);
            colSwap=min(colSwap, n-colSwap);
        }
        return (rowSwap+colSwap)/2;
    }
};
