class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        def dfs(node, parent):
            for neighbor in graph[node]:
                n=abs(neighbor)
                if n==parent: continue
                if (neighbor<0): self.res+=1
                dfs(n, node)
                
        self.res=0
        graph, incoming=collections.defaultdict(list), collections.defaultdict(list)
        for u, v in connections:
            graph[u].append(-v)
            graph[v].append(u)
            
        dfs(0, -1)
        return self.res
