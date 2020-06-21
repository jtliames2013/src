class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        res=start
        for i in range(1, n): res^=2*i+start
        return res

