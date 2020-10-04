class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        cnt=[0]*k
        avail, pq=[i for i in range(k)], []
        for i, a in enumerate(arrival):
            server=i%k
            while pq:
                if pq[0][0]>a: break
                insort_left(avail, heappop(pq)[1])
            if not avail: continue
                
            pos=bisect_left(avail, server)
            if pos==len(avail): pos=0
            cnt[avail[pos]]+=1
            heappush(pq, [a+load[i], avail[pos]])
            avail.pop(pos)
            
        mx=max(cnt)
        res=[i for i, c in enumerate(cnt) if c==mx]
        return res
        
