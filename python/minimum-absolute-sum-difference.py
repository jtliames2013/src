class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        mod=10**9+7
        res, gain, n=0, 0, len(nums1)
        l=nums1.copy()
        l.sort()
        for i in range(n):
            diff=abs(nums1[i]-nums2[i])
            res+=diff
            if diff>gain:
                j=bisect_left(l, nums2[i])
                if j<n: gain=max(gain, diff-(l[j]-nums2[i]))
                if j>0: gain=max(gain, diff-(nums2[i]-l[j-1]))
        
        return (res-gain)%mod

