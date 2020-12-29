class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n, l, r=len(nums), 0, sum(nums)
        res=[0]*n
        for i, v in enumerate(nums):
            res[i]=i*v-l+r-(n-i)*nums[i]
            l+=v
            r-=v
        
        return res

