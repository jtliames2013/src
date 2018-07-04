class Solution:
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        n=len(A)
        swap, noswap=[n]*n, [n]*n
        swap[0], noswap[0]=1, 0
        for i in range(1,n):
            if A[i]>A[i-1] and B[i]>B[i-1]:
                noswap[i]=noswap[i-1]
                swap[i]=swap[i-1]+1
            if A[i]>B[i-1] and B[i]>A[i-1]:
                noswap[i]=min(noswap[i], swap[i-1])
                swap[i]=min(swap[i], noswap[i-1]+1)
        return min(swap[-1], noswap[-1])
