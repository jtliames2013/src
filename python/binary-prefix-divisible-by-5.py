class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        num=0
        res=[0]*len(A)
        for i in range(len(A)):
            num=num*2+A[i]
            res[i]=True if num%5==0 else False
        return res
