class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        def add(s):
            l=list(s)
            for i, c in enumerate(l):
                if i%2==1:
                    l[i]=chr(ord('0')+(ord(c)-ord('0')+a)%10)
            return ''.join(l)
        
        def rotate(s):
            return s[-b:]+s[:-b]
        
        def dfs(s):
            if s in visited: return
            nonlocal res
            if res>s: res=s
            visited.add(s)
            dfs(add(s))
            dfs(rotate(s))
        
        visited=set()
        res=s
        dfs(s)
        return res

