class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n, l, r, ops=len(boxes), 0, 0, 0
        res=[0]*n
        for i in range(n):
            ops+=l
            res[i]+=ops
            if boxes[i]=='1': l+=1
        ops=0
        for i in range(n-1, -1, -1):
            ops+=r
            res[i]+=ops
            if boxes[i]=='1': r+=1
        return res

