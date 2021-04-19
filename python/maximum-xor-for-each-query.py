class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n, xor, mx=len(nums), 0, (1<<maximumBit)-1
        res=[0]*n
        for i, v in enumerate(nums):
            xor^=v
            res[n-i-1]=mx^xor
        return res

