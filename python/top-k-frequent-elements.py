1.
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        return list(zip(*collections.Counter(nums).most_common(k)))[0]

2.
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count=collections.Counter(nums)
        pq=[]
        for i, c in count.items():
            if len(pq)<k: heappush(pq, [c, i])
            elif c>pq[0][0]:
                heappop(pq)
                heappush(pq, [c, i])
        res=[]
        while pq:
            res.append(pq.pop()[1])
        return res

