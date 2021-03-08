class Solution:
    def countHomogenous(self, s: str) -> int:
        mod=10**9+7
        res=0
        for k, g in groupby(s):
            n=len(list(g))
            res+=n*(n+1)//2
        return res%mod

