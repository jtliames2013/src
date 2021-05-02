class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(u):
            if u==n-1: return 1
            res=0
            for v in graph[u].keys():
                if dist[v]<dist[u]: res+=dfs(v)
            return res
        
        mod=10**9+7
        graph=defaultdict(defaultdict)
        for e in edges:
            graph[e[0]-1][e[1]-1]=e[2]
            graph[e[1]-1][e[0]-1]=e[2]
        dist=[float('inf')]*(n-1)+[0]
        pq=[[0, n-1]]
        while pq:
            d, u=heappop(pq)
            if dist[u]<d: continue
            for v, w in graph[u].items():
                if dist[v]>dist[u]+w:
                    dist[v]=dist[u]+w
                    heappush(pq, [dist[u]+w, v])
        
        return dfs(0)%mod
        
