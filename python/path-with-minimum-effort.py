class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n=len(heights), len(heights[0])
        dirs=[[-1, 0], [1, 0], [0, -1], [0, 1]]
        dist=[[float('inf') for j in range(n)] for i in range(m)]
        dist[0][0]=0
        pq=[[0, 0, 0]]
        while pq:
            r, c, d=heappop(pq)
            if r==m-1 and c==n-1: return dist[r][c]
            if dist[r][c]<d: continue
            for dir in dirs:
                nr, nc=r+dir[0], c+dir[1]
                if 0<=nr<m and 0<=nc<n:
                    nd=max(dist[r][c], abs(heights[nr][nc]-heights[r][c]))
                    if dist[nr][nc]>nd:
                        dist[nr][nc]=nd
                        heappush(pq, [nr, nc, nd])
        
        return dist[m-1][n-1]

