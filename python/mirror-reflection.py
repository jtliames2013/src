class Solution:
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        while p%2==0 and q%2==0: p, q=int(p/2), int(q/2)
        return 1-p%2+q%2
