class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnt=collections.Counter(arr)
        res=len(cnt)
        h=list(cnt.values())
        heapq.heapify(h)
        while k>0:
            k-=heapq.heappop(h)
            if k>=0: res-=1
        return res
            
