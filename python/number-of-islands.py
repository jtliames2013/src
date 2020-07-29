1.
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(row, col):
            if row<0 or row>=m or col<0 or col>=n: return
            if grid[row][col]!='1': return
            grid[row][col]='0'
            dfs(row+1, col)
            dfs(row-1, col)
            dfs(row, col+1)
            dfs(row, col-1)
        
        m=len(grid)
        if m==0: return 0
        n=len(grid[0])
        if n==0: return 0
        res=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    dfs(i, j)
                    res+=1
        return res

2.
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(row, col):
            grid[row][col]='0'
            delta=[[1,0], [-1,0], [0,1], [0,-1]]
            for k in range(len(delta)):
                nr=row+delta[k][0]
                nc=col+delta[k][1]
                if 0<=nr<m and 0<=nc<n and grid[nr][nc]=='1':
                    dfs(nr, nc)

        m=len(grid)
        if m==0: return 0
        n=len(grid[0])
        if n==0: return 0
        res=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    dfs(i, j)
                    res+=1
        return res

3.
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def find(i):
            while i!=root[i]: i=root[i]
            return i

        m=len(grid)
        if m==0: return 0
        n=len(grid[0])
        if n==0: return 0
        res=0
        delta=[[1,0], [-1,0], [0,1], [0,-1]]
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    res+=1

        root=[j+i*n for i in range(m) for j in range(n)]
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    for k in range(len(delta)):
                        nr=i+delta[k][0]
                        nc=j+delta[k][1]
                        if 0<=nr<m and 0<=nc<n and grid[nr][nc]=='1':
                            p1=find(i*n+j)
                            p2=find(nr*n+nc)
                            if p1!=p2:
                                root[p1]=p2
                                res-=1
        return res
