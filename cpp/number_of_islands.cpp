#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

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
                
                if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1') {
                    q.push({nr,nc});
                    grid[nr][nc]='2';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        int num=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    bfs(grid, i, j, m, n);
                    num++;
                }
            }
        }
        return num;
    }
    
private:    
    const int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
};

2. DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        grid[row][col]='2';
        for (int k=0; k<4; k++) {
            int nr=row+delta[k][0];
            int nc=col+delta[k][1];
            
            if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1') {
                dfs(grid, nr, nc, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        int num=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='1') {
                    dfs(grid, i, j, m, n);
                    num++;
                }
            }
        }
        return num;
    }
    
private:    
    const int delta[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
};

int main()
{
	return 0;
}


