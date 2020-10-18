class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def isPalin(s, l, r):
            while l<r:
                if s[l]!=s[r]: return False
                l+=1
                r-=1
            return True
        
        def check(a, b):
            n=len(a)
            l, r=0, n-1
            while l<r:
                if a[l]!=b[r]: break
                l+=1
                r-=1
            return isPalin(a, l, r) or isPalin(b, l, r)
        
        return check(a, b) or check(b, a)

