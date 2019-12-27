361. Bomb Enemy 
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Dynamic Programming

Create a 2D array count, where count[i][j] indicates how many enemies can be bombed if placing a bomb here. For each row/column, use head to keep track of how many enemies can be bombed from the beginning to current position, use tail to record how many enemies can be bombed from the end to current position. Then update count[i][j].

For head, If grid[i][j] == ‘W’, set it to 0; else if grid[i][j] == ‘E’, add 1 to it. Same for tail.

We can combine the updating of head and tail into one loop so that each row/column will only be traversed once.

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        vector<vector<int>> cnt(m, vector<int>(n));
                
        for (int i=0; i<m; i++) {
            int head=0, tail=0;
            for (int j=0; j<n; j++) {
                head=grid[i][j]=='W'?0:(head+(grid[i][j]=='E'?1:0));
                if (grid[i][j]=='0') cnt[i][j]+=head;
                tail=grid[i][n-j-1]=='W'?0:(tail+(grid[i][n-j-1]=='E'?1:0));
                if (grid[i][n-j-1]=='0') cnt[i][n-j-1]+=tail;
            }
        }
        
        for (int j=0; j<n; j++) {
            int head=0, tail=0;
            for (int i=0; i<m; i++) {
                head=grid[i][j]=='W'?0:(head+(grid[i][j]=='E'?1:0));
                if (grid[i][j]=='0') cnt[i][j]+=head;
                tail=grid[m-i-1][j]=='W'?0:(tail+(grid[m-i-1][j]=='E'?1:0));
                if (grid[m-i-1][j]=='0') cnt[m-i-1][j]+=tail;
            }
        }
        
        int res=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                res=max(res, cnt[i][j]);
            }
        }
        return res;
    }
};

