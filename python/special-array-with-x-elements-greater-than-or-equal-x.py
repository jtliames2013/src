1.
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n=len(nums)
        nums.sort()
        for i, v in enumerate(nums):
            if n-i<=nums[i] and (i==0 or n-i>nums[i-1]): return n-i
        return -1

2.
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        i, n=0, len(nums)
        nums.sort(reverse=True)
        while i<n and nums[i]>i:
            i+=1
        return i if i==n or nums[i]<i else -1

3.
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        i, n=0, len(nums)
        nums.sort(reverse=True)
        l, r=0, n
        while l<r:
            mid=(l+r)//2
            if nums[mid]>mid: l=mid+1
            else: r=mid
        return l if l==n or nums[l]<l else -1
