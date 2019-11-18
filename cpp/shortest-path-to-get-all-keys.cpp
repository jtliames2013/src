864. Shortest Path to Get All Keys
Hard

262

8

Favorite

Share
We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8
Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6
 

Note:

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.


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
    int shortestPathAllKeys(vector<string>& grid) {
        int res=0, m=grid.size(), n=grid[0].size(), len=0;
        // row, col, key mask
        queue<vector<int>> q;
        unordered_set<vector<int>, VectorHash> visited;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]=='@') {
                    q.push({i, j, 0});
                    visited.insert({i, j, 0});
                } else if (grid[i][j]>='a' && grid[i][j]<='f') {
                    len=max(len, grid[i][j]-'a'+1);
                }
            }
        }
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();            
                                
                for (int k=0; k<4; ++k) {
                    int nr=f[0]+delta[k][0];
                    int nc=f[1]+delta[k][1];
                    int mask=f[2];                    
                    
                    if (nr>=0 && nr<m && nc>=0 && nc<n) {                        
                        if (visited.find({nr, nc, mask})!=visited.end()) continue;
                        if (grid[nr][nc]=='#') continue;
                        if (grid[nr][nc]>='A' && grid[nr][nc]<='F' && (mask & (1<<(grid[nr][nc]-'A')))==0)  continue; 
                        if (grid[nr][nc]>='a' && grid[nr][nc]<='f') {
                            mask|=(1<<(grid[nr][nc]-'a'));
                            if (mask==(1<<len)-1) return res+1;
                        }
                        q.push({nr, nc, mask});
                        visited.insert({nr, nc, mask});
                    }
                }
            }
            res++;
        }
        return -1;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

