class Solution:                    
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(res, nums, start):
            if start==len(nums):
                res.append(nums[:])
                return

            for i in range(start, len(nums)):
                nums[start], nums[i]=nums[i], nums[start]
                dfs(res, nums, start+1)
                nums[start], nums[i]=nums[i], nums[start]
        
        res=[]
        dfs(res, nums, 0)
        return res

