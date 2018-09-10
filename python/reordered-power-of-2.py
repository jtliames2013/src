class Solution:
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        c=collections.Counter(str(N))
        return any(collections.Counter(str(1<<i))==c for i in range(32))
