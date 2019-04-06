class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        res=0
        cnt=[0]*60
        for t in time:
            res+=cnt[(60-t%60)%60]
            cnt[t%60]+=1
        return res
