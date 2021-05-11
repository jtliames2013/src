class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        m, n=len(rooms), len(queries)
        res=[0]*n
        rooms.sort(key=lambda x: x[1], reverse=True)
        sorted_queries=[[i, q] for i, q in enumerate(queries)]
        sorted_queries.sort(key=lambda x: x[1][1], reverse=True)
        
        i, ids=0, []
        for idx, [pre, mn] in sorted_queries:
            while i<m and rooms[i][1]>=mn:
                insort(ids, rooms[i][0])
                i+=1
                
            if ids:
                cand=[]
                j=bisect_left(ids, pre)
                if j>0: cand.append(ids[j-1])
                if j<len(ids): cand.append(ids[j])
                res[idx]=min(cand, key=lambda x: abs(x-pre))
            else:
                res[idx]=-1
        
        return res

