class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        def find(i):
            while i!=root[i]:
                root[i]=root[root[i]]
                i=root[i]
            return i
        
        m, j=len(queries), 0
        res=[False]*m
        root=[i for i in range(n)]
        edgeList.sort(key=lambda e:e[2])
        queries=sorted(enumerate(queries), key=lambda x:x[1][2])
        
        for i, (p, q, dis) in queries:
            while j<len(edgeList) and edgeList[j][2]<dis:
                p1=find(edgeList[j][0])
                p2=find(edgeList[j][1])
                if p1!=p2:
                    root[p1]=p2
                j+=1
            
            res[i]=find(p)==find(q)
        return res

