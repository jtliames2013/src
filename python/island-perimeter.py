class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m=len(grid)
        if m==0: return 0
        n=len(grid[0])
        if n==0: return 0
        islands, neighbors=0, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    if i>0 and grid[i-1][j]==1: neighbors+=1
                    if j>0 and grid[i][j-1]==1: neighbors+=1
                    islands+=1
        return islands*4-neighbors*2

