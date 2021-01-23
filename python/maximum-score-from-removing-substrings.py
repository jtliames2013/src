class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        res, mn, mx=0, min(x, y), max(x, y)
        first='a' if x>y else 'b'
        second='b' if x>y else 'a'
        stk, stk2=[], []
        for c in s:
            if c==second and stk and stk[-1]==first:
                stk.pop()
                res+=mx
            else:
                stk.append(c)
        for c in stk:
            if c==first and stk2 and stk2[-1]==second:
                stk2.pop()
                res+=mn
            else:
                stk2.append(c)            
        
        return res

