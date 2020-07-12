class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum(v*(v-1)//2 for _, v in collections.Counter(nums).items())

