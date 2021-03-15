class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        i, g, n=0, 0, len(nums)
        while i<n and g<len(groups):
            j=0
            while i+j<n and j<len(groups[g]):
                if nums[i+j]!=groups[g][j]: break
                j+=1
            if j==len(groups[g]):
                g+=1
                i+=j
            else:
                i+=1
        return g==len(groups)

