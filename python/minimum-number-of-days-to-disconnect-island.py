class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        def dfs(visited, i, j):
            if i<0 or i>=m or j<0 or j>=n: return
            if grid[i][j]==0 or visited[i][j]==1: return
            visited[i][j]=1
            dfs(visited, i-1, j)
            dfs(visited, i+1, j)
            dfs(visited, i, j-1)
            dfs(visited, i, j+1)            
            
        def count_islands():
            res=0
            visited=[[0 for j in range(n)] for i in range(m)]
            for i in range(m):
                for j in range(n):
                    if grid[i][j]==1 and visited[i][j]==0:
                        dfs(visited, i, j)
                        res+=1
            return res
        
        m, n=len(grid), len(grid[0])
        if count_islands()!=1: return 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    grid[i][j]=0
                    if count_islands()!=1: return 1
                    grid[i][j]=1
                    
        return 2

