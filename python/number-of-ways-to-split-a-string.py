class Solution:
    def numWays(self, s: str) -> int:
        mod=10**9+7
        cnt=s.count('1')
        if cnt%3!=0: return 0
        if cnt==0: return comb(len(s)-1, 2)%mod
        cnt//=3
        ones, first, second=0, 0, 0
        for i, v in enumerate(s):
            if v=='1': ones+=1
            if ones==cnt: first+=1
            if ones==2*cnt: second+=1
        return first*second%mod

