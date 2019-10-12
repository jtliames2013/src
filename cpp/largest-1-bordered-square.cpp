1139. Largest 1-Bordered Square
Medium

79

23

Favorite

Share
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1
 

Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> left(m, vector<int>(n)), top(m, vector<int>(n));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                left[i][j]=grid[i][j]==0?0:(j>0?left[i][j-1]+1:1);
                top[i][j]=grid[i][j]==0?0:(i>0?top[i-1][j]+1:1);
            }
        }
        for (int l=min(m,n); l>0; --l) {
            for (int i=0; i<m-l+1; ++i) {
                for (int j=0; j<n-l+1; ++j) {
                    if (min({left[i][j+l-1], left[i+l-1][j+l-1], top[i+l-1][j], top[i+l-1][j+l-1]})>=l) return l*l;
                }
            }   
        }
        return 0;
    }
};
