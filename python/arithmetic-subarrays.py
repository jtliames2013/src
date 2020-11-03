class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(arr):
            mn, mx, st, n=min(arr), max(arr), set(arr), len(arr)
            step=(mx-mn)//(n-1)
            if step==0: return mn==mx
            for i in range(mn, mx, step):
                if i not in st: return False
            return True
        
        return [check(nums[left:right+1]) for left, right in zip(l, r)]

