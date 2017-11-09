class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
    
        count=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=='1':
                    self.dfs(grid, i, j)
                    count+=1
        return count

    def dfs(self, grid, row, col):
        grid[row][col]='0'
        for dr, dc in [(-1, 0), (1,0), (0,-1), (0,1)]:
            nr=row+dr
            nc=col+dc
            if 0<=nr<len(grid) and 0<=nc<len(grid[0]) and grid[nr][nc]=='1':
                self.dfs(grid, nr, nc)
