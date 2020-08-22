class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def dfs(row, col, ch, pr, pc):
            visited[row][col]=1
            delta=[[-1,0], [1,0], [0,-1], [0,1]]
            for d in delta:
                nr=row+d[0]
                nc=col+d[1]
                if 0<=nr<m and 0<=nc<n and grid[nr][nc]==ch:
                    if nr==pr and nc==pc: continue
                    if visited[nr][nc]==1: return True
                    if dfs(nr, nc, ch, row, col): return True
                        
            return False
            
        m, n=len(grid), len(grid[0])
        visited=[[0 for j in range(n)] for i in range(m)]
        
        for i in range(m):
            for j in range(n):
                if visited[i][j]==0:
                    if dfs(i, j, grid[i][j], -1, -1): return True
        return False

