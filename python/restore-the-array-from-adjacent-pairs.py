class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        res, n=[], len(adjacentPairs)+1
        dic=defaultdict(list)
        for p in adjacentPairs:
            dic[p[0]].append(p[1])
            dic[p[1]].append(p[0])
            
        for k, v in dic.items():
            if len(v)==1:
                res.append(k)
                break
        
        while len(res)<n:
            curr=res[-1]
            next=dic[curr][0]
            dic[curr].remove(next)
            dic[next].remove(curr)
            res.append(next)
            
        return res
            
