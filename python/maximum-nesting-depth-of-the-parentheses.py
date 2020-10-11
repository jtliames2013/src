class Solution:
    def maxDepth(self, s: str) -> int:
        res, open=0, 0
        for c in s:
            if c=='(':
                open+=1
                res=max(res, open)
            elif c==')':
                open-=1
            
        return res

