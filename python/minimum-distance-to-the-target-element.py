class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(start-i) for i, v in enumerate(nums) if v==target)

