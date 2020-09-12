class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        def find(i):
            while root[i]!=i:
                root[i]=root[root[i]]
                i=root[i]
            return i
        
        root=[i for i in range(n+1)]
        res, cnt1, cnt2=0, 0, 0
        for t, i, j in edges:
            if t==3:
                p1=find(i)
                p2=find(j)
                if p1==p2:                    
                    res+=1
                else:
                    root[p1]=p2
                    cnt1+=1
                    cnt2+=1
                    
        tmp=root[:]
        for t, i, j in edges:
            if t==1:
                p1=find(i)
                p2=find(j)
                if p1==p2:                    
                    res+=1
                else:
                    root[p1]=p2
                    cnt1+=1

        root=tmp[:]
        for t, i, j in edges:
            if t==2:
                p1=find(i)
                p2=find(j)
                if p1==p2:
                    res+=1
                else:
                    root[p1]=p2
                    cnt2+=1
        
        return res if cnt1==cnt2==n-1 else -1

