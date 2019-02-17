class Solution:
    def addToArrayForm(self, A: 'List[int]', K: 'int') -> 'List[int]':
        for i in range(len(A))[::-1]:
            A[i]+=K
            K=A[i]//10
            A[i]%=10
        pre=[]
        while K:
            pre.append(K%10)
            K//=10
        return list(reversed(pre))+A

