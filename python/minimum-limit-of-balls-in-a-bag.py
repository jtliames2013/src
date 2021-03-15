class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def get_count(balls):
            res=0
            for i in nums:
                res+=(i-1)//balls
            return res
            
        l, r=1, max(nums)
        while l<r:
            mid=(l+r)//2
            if get_count(mid)>maxOperations: l=mid+1
            else: r=mid
            
        return r

