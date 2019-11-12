1210. Minimum Moves to Reach Target with Rotations
Hard

74

20

Favorite

Share
In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).

In one move the snake can:

Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).

Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).

Return the minimum number of moves to reach the target.

If there is no way to reach the target, return -1.

 

Example 1:



Input: grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
               [0,0,0,0,1,1],
               [0,0,1,0,1,0],
               [0,1,1,0,0,0],
               [0,1,1,0,0,0]]
Output: 11
Explanation:
One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
Example 2:

Input: grid = [[0,0,1,1,1,1],
               [0,0,0,0,1,1],
               [1,1,0,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,1],
               [1,1,1,0,0,0]]
Output: 9
 

Constraints:

2 <= n <= 100
0 <= grid[i][j] <= 1
It is guaranteed that the snake starts at empty cells.

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed=0;
        for (int i:v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int res=0, n=grid.size();
        vector<int> start={0,0,0,1}, end={n-1,n-2,n-1,n-1};
        queue<vector<int>> q;
        unordered_set<vector<int>, VectorHash> visited;
        q.push(start);
        visited.insert(start);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                if (f==end) return res;
                
                int r1=f[0], c1=f[1], r2=f[2], c2=f[3];                
                if (r1==r2) {
                    // rotate clockwise
                    vector<int> next={r1, c1, r1+1, c1};                    
                    if (r1<n-1 && grid[r1+1][c1]==0 && grid[r2+1][c2]==0 && visited.find(next)==visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                } else if (c1==c2) {
                    // rotate counterclockwise
                    vector<int> next={r1, c1, r1, c1+1};                    
                    if (c1<n-1 && grid[r1][c1+1]==0 && grid[r2][c2+1]==0 && visited.find(next)==visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
                        
                vector<int> nr={r1, c1+1, r2, c2+1};                
                if (c2<n-1 && grid[r1][c1+1]==0 && grid[r2][c2+1]==0 && visited.find(nr)==visited.end()) {
                    q.push(nr);
                    visited.insert(nr);
                }
                
                vector<int> nd={r1+1, c1, r2+1, c2};                
                if (r2<n-1 && grid[r1+1][c1]==0 && grid[r2+1][c2]==0 && visited.find(nd)==visited.end()) {
                    q.push(nd);
                    visited.insert(nd);
                }
            }
            res++;
        }
        return -1;
    }
};

