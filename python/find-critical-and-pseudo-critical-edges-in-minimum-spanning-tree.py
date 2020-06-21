class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        def find(root, i):
            while root[i]!=i: i=root[i]
            return i
        
        def getWeight(exclude, include):
            root=[i for i in range(n)]
            weight, count=0, n
            if include!=-1:
                p1=find(root, edges[include][0])
                p2=find(root, edges[include][1])
                root[p1]=p2
                count-=1
                weight+=edges[include][2]
            
            for i in range(len(edges)):
                if i==exclude or i==include: continue
                p1=find(root, edges[i][0])
                p2=find(root, edges[i][1])
                if p1!=p2:
                    root[p1]=p2
                    count-=1
                    weight+=edges[i][2]
                
            return weight if count==1 else float('inf')
        
        critical, pseudo_critical=[], []
        edges=[(u, v, w, i) for i, (u, v, w) in enumerate(edges)]
        edges.sort(key=lambda e: e[2])
        mn=getWeight(-1, -1)
        for i in range(len(edges)):
            if mn<getWeight(i, -1): critical.append(edges[i][3])
            elif mn==getWeight(-1, i): pseudo_critical.append(edges[i][3])
        
        return [critical, pseudo_critical]

