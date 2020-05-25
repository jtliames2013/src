class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n=len(graph)
        partition=[0]*n
        for i in range(n):
            if partition[i]==0:
                q=collections.deque([i])
                partition[i]=1
                while q:
                    f=q.popleft()
                    for neighbor in graph[f]:
                        if partition[neighbor]==partition[f]:
                            return False
                        elif partition[neighbor]==0:
                            partition[neighbor]=-partition[f]
                            q.append(neighbor)
                        
        return True

