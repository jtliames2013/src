class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=collections.Counter(nums)
        odd=0; even=0
        for i in range(10001):
            if i%2==0: even=max(odd, even+i*count[i])
            else: odd=max(even, odd+i*count[i])
        return max(odd,even)

