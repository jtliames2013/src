class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        end=0
        for i in range(len(A)):
            if A[i]%2==0:
                if end!=i: A[end],A[i]=A[i],A[end]
                end+=1
        return A
