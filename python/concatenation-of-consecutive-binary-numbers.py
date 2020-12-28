class Solution:
    def concatenatedBinary(self, n: int) -> int:
        mod=10**9+7
        res, l=0,0
        for i in range(1, n+1):
            if (i & (i-1))==0: l+=1
            res<<=l
            res=(res+i)%mod
        return res

