class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res=0
        st=set(nums)
        for i in st:
            if i-1 not in st:
                j=i+1
                while j in st: j+=1
                res=max(res, j-i)
        return res

