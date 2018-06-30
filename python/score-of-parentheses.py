1.
class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stk=[0]
        for c in S:
            if c=='(':
                stk.append(0)
            else:
                stk[-2]+=1 if stk[-1]==0 else 2*stk[-1]
                stk.pop()
        
        return stk[0]


2.
class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        res=level=0
        for a, b in zip(S, S[1:]):
            level+=1 if a=='(' else -1
            if a=='(' and b==')': res+=2**(level-1)
        return res
