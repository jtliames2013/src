1. BFS
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph=defaultdict(defaultdict)
        for i, e in enumerate(edges):
            graph[e[0]][e[1]]=succProb[i]
            graph[e[1]][e[0]]=succProb[i]
        prob, q=[0]*n, deque([start])
        prob[start]=1
        while q:
            f=q.popleft()
            
            for k, v in graph[f].items():
                if prob[f]*v>prob[k]:
                    prob[k]=prob[f]*v
                    q.append(k)
        
        return prob[end]

2. Dijkstra
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph=defaultdict(defaultdict)
        for i, e in enumerate(edges):
            graph[e[0]][e[1]]=succProb[i]
            graph[e[1]][e[0]]=succProb[i]
        prob, pq=[0]*n, [(-1, start)]
        prob[start]=-1
        while pq:
            pi, i=heappop(pq)
            if prob[i]<pi: continue
            for j, pj in graph[i].items():
                if prob[j]>prob[i]*pj:
                    prob[j]=prob[i]*pj
                    heappush(pq, (prob[j], j))
        
        return -prob[end]

