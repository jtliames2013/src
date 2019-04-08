class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res, cnt=[], 0
        for c in S:
            if c=='(':
                cnt+=1
                if cnt>1: res.append(c)
            else:
                cnt-=1
                if cnt>0: res.append(c)
        return "".join(res)
