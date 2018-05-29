1.
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        n=len(S)
        res=[n]*n
        pos=-n
        for i in range(n): 
            if S[i]==C: pos=i
            res[i]=min(res[i], i-pos)
        pos=2*n
        for i in range(n)[::-1]:
            if S[i]==C: pos=i
            res[i]=min(res[i], pos-i)
        return res

2.
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        n=len(S)
        res=[0 if c==C else n for c in S]
        for i in range(1,n): res[i]=min(res[i], res[i-1]+1)
        for i in range(n-1)[::-1]: res[i]=min(res[i], res[i+1]+1)
        return res

