class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        i, start, end=0, 0, n-1
        while i<=end:
            if nums[i]==0:
                if start!=i:
                    nums[start], nums[i]=nums[i], nums[start]
                start+=1
                i+=1
            elif nums[i]==1:
                i+=1
            else:
                nums[i], nums[end]=nums[end], nums[i]
                end-=1

