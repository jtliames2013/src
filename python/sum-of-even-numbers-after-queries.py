class Solution:
    def sumEvenAfterQueries(self, A: 'List[int]', queries: 'List[List[int]]') -> 'List[int]':
        res, s=[], 0
        for i in A:
            if i%2==0: s+=i
        
        for v, i in queries:
            prev=A[i]
            A[i]+=v
            if prev%2==0:
                s-=prev
            if A[i]%2==0:
                s+=A[i]
            res.append(s)
        return res

