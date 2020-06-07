class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        left, right=0, 0
        for c in S:
            if c=='(': left+=1
            elif left>0: left-=1
            else: right+=1
        return left+right

