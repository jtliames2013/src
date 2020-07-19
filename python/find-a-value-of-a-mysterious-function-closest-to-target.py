class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        res, s=float('inf'), set()
        for a in arr:
            s={a&b for b in s} | {a}
            for b in s: res=min(res, abs(b-target))
        return res
