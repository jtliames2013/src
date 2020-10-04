class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n<=1: return n
        b=1
        while (b<=n): b<<=1
        return (b-1)-self.minimumOneBitOperations(n-(b>>1))

