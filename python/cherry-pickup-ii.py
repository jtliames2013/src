class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(row, col1, col2):
            res=0
            if row==m: return 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    nc1, nc2=col1+i, col2+j
                    if 0<=nc1<n and 0<=nc2<n:
                        res=max(res, dfs(row+1, nc1, nc2))       
            res+=grid[row][col1] if col1==col2 else grid[row][col1]+grid[row][col2]    
            return res
        
        m, n=len(grid), len(grid[0])
        return dfs(0, 0, n-1)

