class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        d=collections.defaultdict(int)
        d[0]=-1
        res, lower, sum=0, -1, 0
        for i, v in enumerate(nums):
            sum+=v
            if sum-target in d and d[sum-target]>=lower:
                res+=1
                lower=i
            d[sum]=i
        return res

