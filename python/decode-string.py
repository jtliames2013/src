class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stk=[]
        stk.append(["", 1])
        num=""
        for c in s:
            if c.isdigit():
                num+=c
            elif c=='[':
                stk.append(["", int(num)])
                num=""
            elif c==']':
                st, n=stk.pop()
                stk[-1][0]+=st*n
            else:
                stk[-1][0]+=c
        return stk[0][0]

