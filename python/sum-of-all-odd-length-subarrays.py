class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        res, n=0, len(arr)
        for i in range(n):
            res+=((i+1)*(n-i)+1)//2*arr[i]
        return res

