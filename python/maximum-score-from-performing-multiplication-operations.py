class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        @lru_cache(1000)
        def dfs(i, l):
            if i==n: return 0
            return max(multipliers[i]*nums[l]+dfs(i+1, l+1), multipliers[i]*nums[m-1-(i-l)]+dfs(i+1, l))
        
        m, n=len(nums), len(multipliers)
        return dfs(0, 0)

