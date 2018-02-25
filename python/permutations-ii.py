class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        nums.sort()
        self.dfs(res, nums, 0)
        return res
    
    def dfs(self, res, nums, start):
        if start==len(nums):
            res.append(nums)
            return
        
        for i in range(start, len(nums)):
            if i!=start and nums[i]==nums[start]: continue
            nums[start], nums[i]=nums[i], nums[start]
            self.dfs(res, list(nums), start+1)
