class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        res, prev=0, 0
        for i, v in enumerate(target):
            res+=max(0, v-prev)
            prev=v
        return res

