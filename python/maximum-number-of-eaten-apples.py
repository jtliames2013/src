class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        res, pq, i, n=0, [], 0, len(apples)
        while i<n or pq:
            if i<n: heappush(pq, [i+days[i], apples[i]])
            while pq and (pq[0][0]<=i or pq[0][1]==0):
                heappop(pq)
            if pq:
                pq[0][1]-=1
                res+=1
            i+=1
        return res

