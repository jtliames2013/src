class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        res, m, n=0, len(s), len(t)
        l=[[0 for j in range(101)] for i in range(101)]
        r=[[0 for j in range(101)] for i in range(101)]
        for i in range(1, m):
            for j in range(1, n):
                if s[i-1]==t[j-1]: l[i][j]=1+l[i-1][j-1]
        
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                if s[i+1]==t[j+1]: r[i][j]=1+r[i+1][j+1]
                    
        for i in range(m):
            for j in range(n):
                if s[i]!=t[j]: res+=(l[i][j]+1)*(r[i][j]+1)
        
        return res

