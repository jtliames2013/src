class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res=[]
        for n in nums:
            i=abs(n)-1
            if nums[i]<0: res.append(i+1)
            nums[i]=-nums[i]
        return res

