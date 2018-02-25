class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stk, res=[], 0
        for i in range(len(s)):
            if s[i]=='(': stk.append(i)
            else:
                if len(stk)==0 or s[stk[-1]]==')':
                    stk.append(i)
                else:
                    stk.pop()
                    res=max(res, (i+1 if len(stk)==0 else i-stk[-1]))
        
        return res
