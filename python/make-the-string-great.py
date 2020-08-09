class Solution:
    def makeGood(self, s: str) -> str:
        stk=[]
        for c in s:
            if stk and abs(ord(stk[-1])-ord(c))==32:
                stk.pop()
            else:
                stk.append(c)
        return ''.join(stk)
