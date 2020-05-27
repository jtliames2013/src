class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(row, col):
            if 0<=row<m and 0<=col<n and grid[row][col]:
                grid[row][col]=0
                return 1+dfs(row-1, col)+dfs(row+1, col)+dfs(row, col-1)+dfs(row, col+1)
            return 0
        m, n=len(grid), len(grid[0])
        areas=[dfs(i, j) for i in range(m) for j in range(n) if grid[i][j]]
        return max(areas) if areas else 0
        
