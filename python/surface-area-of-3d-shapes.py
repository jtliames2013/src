class Solution:
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res, m, n=0, len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]>0: res+=grid[i][j]*4+2
                if i>0: res-=(min(grid[i-1][j], grid[i][j]))*2
                if j>0: res-=(min(grid[i][j-1], grid[i][j]))*2
                    
        return res
