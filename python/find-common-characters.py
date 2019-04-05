class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        res=collections.Counter(A[0])
        for a in A:
            res &= collections.Counter(a)
        return list(res.elements())
