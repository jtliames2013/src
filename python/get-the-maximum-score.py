class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        res, a, b, i, j, m, n=0, 0, 0, 0, 0, len(nums1), len(nums2)
        mod=10**9+7
        while i<m or j<n:
            if i<m and (j==n or nums1[i]<nums2[j]):
                a+=nums1[i]
                i+=1
            elif j<n and (i==m or nums1[i]>nums2[j]):
                b+=nums2[j]
                j+=1
            else:
                res+=max(a, b)+nums1[i]
                a, b=0, 0
                i+=1
                j+=1
        return (res+max(a, b))%mod

