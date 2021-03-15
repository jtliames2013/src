class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n=len(isWater), len(isWater[0])
        res=[[-1]*n for _ in range(m)]
        q=deque([])
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    res[i][j]=0
                    q.append([i, j])
                    
        delta=[[1,0], [-1,0], [0,1], [0,-1]]
        while q:
            f=q.popleft()
            for d in delta:
                nr, nc=f[0]+d[0], f[1]+d[1]
                if 0<=nr<m and 0<=nc<n and res[nr][nc]==-1:
                    res[nr][nc]=res[f[0]][f[1]]+1
                    q.append([nr, nc])
            
        return res

