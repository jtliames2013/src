class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk=[]
        for i, c in enumerate(s):
            if c=='(': stk.append(i)
            elif c==')':
                if stk and s[stk[-1]]=='(': stk.pop()
                else: stk.append(i)
        st=set(stk)
        return ''.join(s[i] for i in range(len(s)) if i not in st)

