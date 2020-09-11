class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def count(n, nums):
            cnt, d=0, collections.defaultdict(int)
            for i in nums:
                if n%i==0 and n//i in d: 
                    cnt+=d[n//i]
                d[i]+=1
            return cnt
        
        res=0
        for i in nums1:
            res+=count(i*i, nums2)
        for i in nums2:
            res+=count(i*i, nums1)
        return res

