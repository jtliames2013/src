class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n=len(rains)
        res=[-1]*n
        full, dry={}, []
        for i, lake in enumerate(rains):
            if lake>0:
                if lake in full:
                    pos=bisect.bisect(dry, full[lake])
                    if pos==len(dry): return []
                    else: 
                        res[dry[pos]]=lake
                        del dry[pos]
                        full[lake]=i
                else:
                    full[lake]=i
            else:
                dry.append(i)
                res[i]=1
        return res

