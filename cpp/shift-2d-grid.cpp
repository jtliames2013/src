1260. Shift 2D Grid
Easy

53

36

Favorite

Share
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] becomes at grid[i][j + 1].
Element at grid[i][n - 1] becomes at grid[i + 1][0].
Element at grid[n - 1][n - 1] becomes at grid[0][0].
Return the 2D grid after applying shift operation k times.

 

Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
Example 2:


Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        k%=m*n;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int idx=(i*n+j+k)%(m*n), ni=idx/n, nj=idx%n;
                res[ni][nj]=grid[i][j];
            }
        }
        return res;
    }
};

2. in place
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        k%=m*n;
        reverse(grid, 0, m*n-1);
        reverse(grid, 0, k-1);
        reverse(grid, k, m*n-1);
        return grid;
    }
private:
    void reverse(vector<vector<int>>& grid, int lower, int upper) {
        int n=grid[0].size();
        while (lower<upper) {
            int r1=lower/n, c1=lower%n, r2=upper/n, c2=upper%n;
            swap(grid[r1][c1], grid[r2][c2]);
            lower++;
            upper--;
        }
    }
};

