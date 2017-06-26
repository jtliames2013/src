200. Number of Islands Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 97866
Total Submissions: 292438
Difficulty: Medium
Contributor: LeetCode
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Depth-first Search Breadth-first Search Union Find
Hide Similar Problems (M) Surrounded Regions (M) Walls and Gates (H) Number of Islands II (M) Number of Connected Components in an Undirected Graph

1. BFS
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col]='2';
        
        while (!q.empty()) {
            pair<int,int> f=q.front();
            q.pop();
            for (int k=0; k<4; k++) {
                int nr=f.first+delta[k][0];
                int nc=f.second+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1') {
                    q.push({nr,nc});
                    grid[nr][nc]='2';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int sum=0;
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    bfs(grid, i, j, m, n);
                    sum++;
                }
            }
        }
        return sum;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        grid[row][col]='2';
        
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1') {
                dfs(grid, nr, nc, m, n);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int sum=0;
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    dfs(grid, i, j, m, n);
                    sum++;
                }
            }
        }
        return sum;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

