class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        res=0
        arr.sort()
        for a in arr:
            res=min(res+1, a)
        return res

