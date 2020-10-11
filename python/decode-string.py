class Solution:
    def decodeString(self, s: str) -> str:
        res, num, stk='', '', []
        for c in s:
            if c.isdigit():
                num+=c
            elif c=='[':
                stk.append([res, int(num)])
                res, num='', ''
            elif c==']':
                st, n=stk.pop()
                res=st+res*n
            else:
                res+=c
        return res

