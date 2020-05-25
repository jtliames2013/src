class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        res=[]
        if not nums1 or not nums2: return res
        pq=[[nums1[0]+nums2[0], 0, 0]]
        while pq and k>0:
            _, i, j=heappop(pq)
            res.append([nums1[i], nums2[j]])
            if i==0 and j<len(nums2)-1: heappush(pq, [nums1[i]+nums2[j+1], i, j+1])
            if i<len(nums1)-1: heappush(pq, [nums1[i+1]+nums2[j], i+1, j])
            k-=1
        return res

