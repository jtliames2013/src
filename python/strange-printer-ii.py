class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        def dfs(start):
            visited[start]=1
            for neighbor in graph[start]:
                if visited[neighbor]==1: return True
                if visited[neighbor]==0:
                    if dfs(neighbor): return True
            visited[start]=2
            return False
                
        m, n=len(targetGrid), len(targetGrid[0])
        graph=[set() for i in range(61)]
        visited=[0 for i in range(61)]
        for i in range(61):
            rl=cl=61
            ru=cu=-1
            for j in range(m):
                for k in range(n):
                    if targetGrid[j][k]==i:
                        rl=min(rl, j)
                        ru=max(ru, j)
                        cl=min(cl, k)
                        cu=max(cu, k)
                        
            for r in range(rl, ru+1):
                for c in range(cl, cu+1):
                    if targetGrid[r][c]!=i:
                        graph[i].add(targetGrid[r][c])
                        
        for i in range(61):
            if not visited[i] and dfs(i):
                return False
        return True

