class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def getSum(num):
            res=num
            a, b=max(num-index, 0), num-1
            res+=(a+b)*(b-a+1)//2
            a, b=max(num-(n-1-index), 0), num-1
            res+=(a+b)*(b-a+1)//2
            return res
        
        maxSum-=n
        l, r=0, maxSum
        while l<r:
            mid=l+(r-l)//2+1
            if getSum(mid)>maxSum: r=mid-1
            else: l=mid
        return l+1

