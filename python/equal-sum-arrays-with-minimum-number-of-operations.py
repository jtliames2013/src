class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sums1, sums2=sum(nums1), sum(nums2)
        if sums1>sums2: return self.minOperations(nums2, nums1)
        
        n1, n2=len(nums1), len(nums2)
        if n2>6*n1: return -1
        
        res, delta, i=0, sums2-sums1, 5
        cnt=Counter([6-i for i in nums1] + [i-1 for i in nums2])
        while delta>0:
            if cnt[i]==0:
                i-=1
            delta-=i
            cnt[i]-=1
            res+=1
        return res
        
