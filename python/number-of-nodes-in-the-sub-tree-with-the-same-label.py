class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        def dfs(i, parent):
            d=collections.defaultdict(int)
            d[labels[i]]+=1
            for neighbor in graph[i]:
                if neighbor==parent: continue
                nd=dfs(neighbor, i)
                for k, v in nd.items():
                    d[k]+=v
            res[i]=d[labels[i]]
            return d

        res=[0]*n
        graph=[[] for i in range(n)]
        for e in edges: 
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        dfs(0, -1)
        return res

