class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n, l, r, ops=len(boxes), 0, 0, 0
        res=[0]*n
        for i in range(n):
            ops+=l
            res[i]+=ops
            l+=int(boxes[i])
        ops=0
        for i in reversed(range(n)):
            ops+=r
            res[i]+=ops
            r+=int(boxes[i])
        return res

