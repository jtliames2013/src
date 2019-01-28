class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        up, down=False, False
        for i in range(1, len(A)):
            if A[i]>A[i-1]:
                if down: return False
                up=True
            elif A[i]<A[i-1]:
                if not up: return False
                down=True
            else:
                return False
        return up and down

