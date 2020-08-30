class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        def dfs(arr):
            n=len(arr)
            if n<=1: return 1
            left, right=[], []
            for i in range(1, n):
                if arr[i]<arr[0]: left.append(arr[i])
                else: right.append(arr[i])
            l, r=len(left), len(right)
            return comb(n-1, l)*dfs(left)*dfs(right)
                    
        mod=10**9+7
        return (dfs(nums)-1)%mod

