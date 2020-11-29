class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        res, n=[], len(nums)
        for i in range(n):
            while res and res[-1]>nums[i] and len(res)-1+n-i>=k:
                res.pop()
            if len(res)<k: res.append(nums[i])
        
        return res

