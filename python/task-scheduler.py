class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        res, cycle, pq=0, n+1, []
        for v in collections.Counter(tasks).values():
            heappush(pq, -v)
        
        while pq:
            cnt=[]
            for i in range(cycle):
                if not pq: break
                cnt.append(heappop(pq))
                
            for c in cnt:
                if c<-1: heappush(pq, c+1)
            
            res+=cycle if pq else len(cnt)
            
        return res

