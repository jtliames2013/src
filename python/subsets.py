class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(output, nums, start):
            res.append(output[:])
            
            for i in range(start, len(nums)):
                output.append(nums[i])
                dfs(output, nums, i+1)
                output.pop()
                
        res, output=[], []
        dfs(output, nums, 0)
        return res

