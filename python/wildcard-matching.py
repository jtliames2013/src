class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i, j, sIdx, pIdx, m, n=0, 0, 0, 0, len(s), len(p)
        star=False
        while i<m:
            if j==n:
                if not star: return False
                else:
                    j=pIdx
                    sIdx+=1
                    i=sIdx
                    
            if p[j]=='?':
                i+=1
                j+=1
            elif p[j]=='*':
                while j<n:
                    if p[j]!='*': break
                    j+=1
                if j==n: return True
                star, sIdx, pIdx=True, i, j
            else:
                if s[i]==p[j]:
                    i+=1
                    j+=1
                else:
                    if not star: return False
                    star=True
                    j=pIdx
                    sIdx+=1
                    i=sIdx
        
        while j<n:
            if p[j]!='*': break
            j+=1
        return j==n
        
