1. Priority queue
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        res=float('-inf')
        pq=[]
        for x, y in points:
            while pq and x-pq[0][1]>k: heappop(pq)
            if pq: res=max(res, x+y-pq[0][0])
            heappush(pq, [-y+x, x])
        
        return res

2. Deque
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        res=float('-inf')
        dq=deque()
        for x, y in points:
            while dq and x-dq[0][1]>k: dq.popleft()
            if dq: res=max(res, x+y+dq[0][0])
            while dq and y-x>=dq[-1][0]: dq.pop()
            dq.append([y-x, x])
            
        return res

