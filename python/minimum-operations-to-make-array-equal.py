class Solution:
    def minOperations(self, n: int) -> int:
        i=n//2
        return i*(i+n%2)

