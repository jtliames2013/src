class Solution:
    def sortedSquares(self, A: 'List[int]') -> 'List[int]':
        n=len(A)
        res=[None]*n
        i, s, e=n-1, 0, n-1
        while s<=e:
            if abs(A[s])<abs(A[e]):
                res[i]=A[e]*A[e]      
                e-=1
            else:
                res[i]=A[s]*A[s]
                s+=1
            i-=1
        return res

