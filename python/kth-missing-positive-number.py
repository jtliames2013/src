class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        n=len(arr)
        l, r=-1, n-1
        while l<r:
            m=(r+l)//2+1
            if arr[m]-m-1<k: l=m
            else: r=m-1
        return k+l+1

