class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        return heapq.nsmallest(K, points, lambda (x, y): x*x+y*y)

2.
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        res, pq=[], []
        for p in points:
            d=p[0]*p[0]+p[1]*p[1]
            if len(pq)<K: heappush(pq, [-d, p[0], p[1]])
            elif d<-pq[0][0]:
                heappop(pq)
                heappush(pq, [-d, p[0], p[1]])
        while pq:
            d, i, j=heappop(pq)
            res.append([i, j])
        return res

