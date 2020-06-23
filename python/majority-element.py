class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate, count=0, 0
        for _, v in enumerate(nums):
            if count==0:
                candidate=v
                count=1
            elif v==candidate:
                count+=1
            else:
                count-=1
        return candidate
                
