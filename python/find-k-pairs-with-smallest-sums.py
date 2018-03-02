class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        res=[]
        if len(nums1)==0 or len(nums2)==0: return res
        
        h=[]
        heapq.heappush(h, [nums1[0]+nums2[0], 0, 0])
        
        while len(h)>0 and k>0:
            _, i, j=heapq.heappop(h)
            res.append([nums1[i], nums2[j]])
            if i<len(nums1)-1:
                heapq.heappush(h, [nums1[i+1]+nums2[j], i+1, j])
            if i==0 and j<len(nums2)-1:
                heapq.heappush(h, [nums1[i]+nums2[j+1], i, j+1])
            k-=1
            
        return res
        
