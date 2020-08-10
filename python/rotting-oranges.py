class Solution:
    def orangesRotting(self, grid: 'List[List[int]]') -> 'int':
        m, n=len(grid), len(grid[0])
        q=[]
        count, minutes=0, -1
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2: q.append([i,j])
                elif grid[i][j]==1: count+=1
        if count==0: return 0
        
        while q:
            size=len(q)
            for i in range(size):
                f=q.pop(0)
                for nr, nc in [(f[0]-1, f[1]), (f[0],f[1]-1), (f[0]+1, f[1]), (f[0], f[1]+1)]:
                    if nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1:
                        grid[nr][nc]=2
                        count-=1
                        q.append([nr,nc])
            minutes+=1
            
        return minutes if count==0 else -1

