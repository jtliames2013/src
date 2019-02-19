ass Solution:
    def lenLongestFibSubseq(self, A: 'List[int]') -> 'int':
        dp=collections.defaultdict(int)
        st=set(A)
        for i in range(len(A)):
            for j in range(i):
                if A[i]-A[j]<A[j] and A[i]-A[j] in st:
                    dp[A[j], A[i]]=dp.get((A[i]-A[j], A[j]), 2)+1
        return max(dp.values() or [0])

