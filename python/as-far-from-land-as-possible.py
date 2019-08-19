class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        res,m,n=-1,len(grid),len(grid[0])
        q=collections.deque([i,j] for i in range(m) for j in range(n) if grid[i][j]==1)
        
        while q:
            size=len(q)
            for _ in range(size):
                r,c=q.popleft()
                for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                    nr,nc=r+dr,c+dc
                    if nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==0:
                        q.append((nr,nc))
                        grid[nr][nc]=1
            res+=1
            
        return -1 if res<=0 else res
