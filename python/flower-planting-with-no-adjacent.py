class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        res=[0]*N
        graph=[[] for i in range(N)]
        for p in paths:
            graph[p[0]-1].append(p[1]-1)
            graph[p[1]-1].append(p[0]-1)
        for i in range(N):
            used=[False]*5
            for neighbor in graph[i]: used[res[neighbor]]=True
            for j in range(1,5):
                if used[j]==False:
                    res[i]=j
                    break
        
        return res
