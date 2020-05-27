1.
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        back = lambda res, c : res[:-1] if c=='#' else res+c
        return reduce(back, S, "") == reduce(back, T, "")
2.
class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        i, j=len(S)-1, len(T)-1
        while True:
            b=0
            while i>=0:
                if S[i]!='#' and b==0: break
                b+=1 if S[i]=='#' else -1
                i-=1
            b=0
            while j>=0:
                if T[j]!='#' and b==0: break
                b+=1 if T[j]=='#' else -1
                j-=1
            
            if i>=0 and j>=0:
                if S[i]!=T[j]: return False
            else:
                return i==-1 and j==-1
            
            i-=1
            j-=1
