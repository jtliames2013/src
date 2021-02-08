class Solution:
    def minimumLength(self, s: str) -> int:
        n=len(s)
        l, r=0, n-1
        while l<=r:
            if s[l]!=s[r] or r==l: break
            c=s[l]
            while l<=r and s[l]==c: l+=1
            while l<=r and s[r]==c: r-=1
        
        return r-l+1

