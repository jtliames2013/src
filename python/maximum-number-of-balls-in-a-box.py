class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        res, cnt=0, defaultdict(int)
        
        for i in range(lowLimit, highLimit+1):
            sum=0
            while i>0:
                sum+=i%10
                i//=10
            cnt[sum]+=1
            res=max(res, cnt[sum])
        return res

