1.
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

2.
class Solution:
    def decodeString(self, s: str) -> str:
        res, stk, i, n='', [], 0, len(s)
        while i<n:
            if s[i].isdigit():
                num=0
                j=i
                while j<n and s[j].isdigit():
                    num=num*10+ord(s[j])-ord('0')
                    j+=1
                i=j
            elif s[i]=='[':
                stk.append([res, num])
                res=''
                i+=1
            elif s[i]==']':
                st, num=stk.pop()
                res=st+res*num
                i+=1
            else:
                res+=s[i]
                i+=1
        return res

