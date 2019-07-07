class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-s for s in stones]
        heapq.heapify(pq)
        for i in range(len(stones)-1):
            d=heapq.heappop(pq)-heapq.heappop(pq)
            heapq.heappush(pq, d)
        return -pq[0]

