class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod=10**9+7
        res, odd, even=0, 0, 0
        for a in arr:
            even+=1
            if a%2==1:
                odd, even=even, odd
            res=(res+odd)%mod
        return res

