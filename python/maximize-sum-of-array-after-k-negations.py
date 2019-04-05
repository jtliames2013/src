class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        i=0
        while K>0 and i<len(A) and A[i]<0:
            A[i]=-A[i]
            K-=1
            i+=1
        return sum(A)-(K%2)*min(A)*2
