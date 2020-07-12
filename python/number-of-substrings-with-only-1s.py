class Solution:
    def numSub(self, s: str) -> int:
        mod=10**9+7
        return sum(len(sub)*(len(sub)+1)//2%mod for sub in s.split('0'))

