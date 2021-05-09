class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        res=0
        n1, n2, i1, i2=len(nums1), len(nums2), 0, 0
        while i1<n1 and i2<n2:
            if nums1[i1]>nums2[i2]:
                i1+=1
            else:
                res=max(res, i2-i1)
                i2+=1
        return res

