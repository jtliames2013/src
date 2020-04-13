class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        res=[]
        P=list(range(1, m+1))
        for q in queries:
            i=P.index(q)
            res.append(i)
            P=[q]+P[:i]+P[i+1:]
            
        return res

