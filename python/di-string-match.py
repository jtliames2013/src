class Solution:
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        n=len(S)
        A=[None]*(n+1)
        start, end=0, n
        for i in range(len(S)):
            if S[i]=='I':
                A[i]=start
                start+=1
            else:
                A[i]=end
                end-=1
        A[n]=start
        return A

