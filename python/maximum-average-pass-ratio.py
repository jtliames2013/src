class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        pq=[(-((p+1)/(t+1)-p/t), p, t) for p, t in classes]
        heapify(pq)
        
        while extraStudents>0:
            r, p, t=heappop(pq)
            heappush(pq, (-((p+2)/(t+2)-(p+1)/(t+1)), p+1, t+1))
            extraStudents-=1
        return sum(p/t for r, p, t in pq)/len(classes)

