1.
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        d = {}
        for i, num in enumerate(nums):
            if target-num in d:
                return [d[target-num], i]
            else:
                d[num]=i
        return res
            
2.
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        index_num = enumerate(nums)
        sorted_index_num = sorted(index_num, key=lambda x:x[1])    
        l,r=0, len(nums)-1
        while l<r:
            if sorted_index_num[l][1]+sorted_index_num[r][1]==target:
                return [sorted_index_num[l][0], sorted_index_num[r][0]]
            elif sorted_index_num[l][1]+sorted_index_num[r][1]<target:
                l+=1
            else:
                r-=1
        return res
            
