class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        count=collections.Counter(nums)
        return sorted(nums, key=lambda a: (count[a], -a))

