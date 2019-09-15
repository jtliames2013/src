840. Magic Squares In Grid
DescriptionHintsSubmissionsDiscussSolution
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15

class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        if (grid[r+1][c+1]!=5) return false;
        bitset<9> b;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                int row=r+i, col=c+j;
                if (grid[row][col]<1 || grid[row][col]>9) return false;
                if (b.test(grid[row][col]-1)) return false;
                b.set(grid[row][col]-1);
                if (edge.find({i,j})!=edge.end() && grid[row][col]%2!=1) return false;
                if (corner.find({i,j})!=corner.end() && grid[row][col]%2!=0) return false;
            }
        }
        if (grid[r][c]+grid[r+2][c+2]!=10) return false;
        if (grid[r+1][c]+grid[r+1][c+2]!=10) return false;
        if (grid[r][c]+grid[r][c+1]+grid[r][c+2]!=15) return false;
        if (grid[r][c]+grid[r+1][c]+grid[r+2][c]!=15) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        int res=0;
        for (int i=0; i<m-2; ++i) {
            for (int j=0; j<n-2; ++j) {
                if (isMagic(grid, i, j)) res++;
            }
        }
        return res;
    }
private:
    set<pair<int,int>> edge={{0,1}, {1,0}, {1,2}, {2,1}};
    set<pair<int,int>> corner={{0,0}, {0,2}, {2,0}, {2,2}};
};
