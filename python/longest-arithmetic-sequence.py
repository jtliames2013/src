class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        res, n=2, len(A)
        d=collections.defaultdict(dict)
        for i in range(n):
            for j in range(i+1, n):
                dist=A[j]-A[i]
                d[dist][j]=d[dist][i]+1 if i in d[dist] else 2
                res=max(res, d[dist][j])
        return res

