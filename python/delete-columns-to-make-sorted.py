class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        return sum(list(col)!=sorted(col) for col in zip(*A))
