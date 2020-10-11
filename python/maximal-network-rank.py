class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        res=0
        graph=collections.defaultdict(set)
        for r in roads:
            graph[r[0]].add(r[1])
            graph[r[1]].add(r[0])
        
        for i in range(n):
            for j in range(i+1, n):
                res=max(res, len(graph[i])+len(graph[j])-(1 if i in graph[j] else 0))
        
        return res
