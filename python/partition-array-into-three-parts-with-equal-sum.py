class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total=sum(A)
        if total%3!=0: return False
        i, parts, s=0, 0, 0
        while i<len(A) and parts<2:
            s+=A[i]
            if s==total/3:
                parts+=1
                s=0
            i+=1
        return parts==2
