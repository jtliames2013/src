class Solution:
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        return max(["%d%d:%d%d"%t for t in itertools.permutations(A) if t[:2]<(2,4) and t[2]<6] or [""])

