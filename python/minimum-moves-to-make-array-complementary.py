class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        res, curr=float('inf'), 0
        d=collections.defaultdict(int)
        n=len(nums)
        for i in range(n//2):
            a, b=nums[i], nums[n-i-1]
            d[2]+=2
            d[min(a, b)+1]-=1
            d[a+b]-=1
            d[a+b+1]+=1
            d[max(a,b)+limit+1]+=1
            
        for i in range(2, 2*limit+1):
            curr+=d[i]
            res=min(res, curr)
        return res
        
