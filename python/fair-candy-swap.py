class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        target=(sum(A)-sum(B))/2
        st=set(A)
        for i in B:
            if i+target in st: return [i+target, i]
        
