class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target=sum(nums)-x
        if target==0: return len(nums)
        d=collections.defaultdict(int)
        d[0]=-1
        s, l=0, 0
        for i, v in enumerate(nums):
            s+=v
            if s-target in d: l=max(l, i-d[s-target])
            if s not in d: d[s]=i
        return len(nums)-l if l>0 else -1

