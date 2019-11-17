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


Intuition:
Two conditions to help solve this problem:

In a valid chess board, there are 2 and only 2 kinds of rows and one is inverse to the other.
For example if there is a row 01010011 in the board, any other row must be either 01010011 or 10101100.
The same for columns
A corollary is that, any rectangle inside the board with corners top left, top right, bottom left, bottom right must be 4 zeros or 2 ones 2 zeros or 4 zeros.

Another important property is that every row and column has half ones. Assume the board is N * N:
If N = 2*K, every row and every column has K ones and K zeros.
If N = 2*K + 1, every row and every column has K ones and K + 1 zeros or K + 1 ones and K zeros.


Explanation:
Since the swap process does not break this property, for a given board to be valid, this property must hold.
These two conditions are necessary and sufficient condition for a valid chessboard.

Once we know it is a valid cheese board, we start to count swaps.
Basic on the property above, when we arange the first row, we are actually moving all columns.

I try to arrange one row into 01010 and 10101 and I count the number of swaps.

In case of N even, I take the minimum swaps, because both are possible.
In case of N odd, I take the even swaps.
Because when we make a swap, we move 2 columns or 2 rows at the same time.
So col swaps and row swaps should be same here.


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
