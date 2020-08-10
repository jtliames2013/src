class Solution:
    def minInsertions(self, s: str) -> int:
        left, right=0, 0
        for c in s:
            if c=='(':
                if right%2==1:
                    # right parenthesis is separated now
                    # move one right count to left count
                    right-=1
                    left+=1
                right+=2
            else:
                if right>0: right-=1
                else:
                    right=1
                    left+=1
        return left+right

