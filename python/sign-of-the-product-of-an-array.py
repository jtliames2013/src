class Solution:
    def arraySign(self, nums: List[int]) -> int:
        res=1
        for _, v in enumerate(nums):
            if v==0: return 0
            elif v<0: res=-res
        return res

