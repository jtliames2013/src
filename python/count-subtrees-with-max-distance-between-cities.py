class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        def maxDist(state):
            res, nodes, edges=0, 0, 0
            for i in range(n):
                if (((1<<i) & state)==0): continue
                nodes+=1
                for j in range(i+1, n):
                    if (((1<<j) & state)==0): continue
                    if dist[i][j]==1: edges+=1
                    res=max(res, dist[i][j])
            if edges!=nodes-1: return 0
            return res
        
        res=[0]*(n-1)
        dist=[[float('inf') for j in range(n)] for i in range(n)]
        for u, v in edges:
            dist[u-1][v-1]=dist[v-1][u-1]=1
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j])
        
        for state in range(1, 1<<n):
            d=maxDist(state)
            if d>0: res[d-1]+=1
        return res

