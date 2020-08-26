class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0
        maxLocal, minLocal, maxGlobal=1, 1, float('-inf')
        for i in nums:
            tmp=maxLocal
            maxLocal=max(maxLocal*i, minLocal*i, i)
            minLocal=min(tmp*i, minLocal*i, i)
            maxGlobal=max(maxGlobal, maxLocal)
        return maxGlobal

