class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        n=math.ceil(len(B)/len(A))
        for i in range(2):
            if B in (A*(n+i)): return n+i
        return -1
