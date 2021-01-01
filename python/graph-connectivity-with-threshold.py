class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        def find(i):
            if i!=root[i]:
                root[i]=find(root[i])        
            return root[i]
        
        res=[False]*len(queries)
        root=[i for i in range(n+1)]
        for i in range(threshold+1, n+1):
            m=1
            while i*m<=n:
                p1=find(i)
                p2=find(i*m)
                if p1!=p2: root[p1]=p2
                m+=1
                
        for i, q in enumerate(queries):
            p1=find(q[0])
            p2=find(q[1])
            res[i]=p1==p2
        
        return res

