class Solution:

    def __init__(self, nums: List[int]):
        self.nums=nums

    def pick(self, target: int) -> int:
        count=0
        for i, n in enumerate(self.nums):
            if n==target:
                count+=1
                if randrange(0, count)==0: res=i
        return res


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)

