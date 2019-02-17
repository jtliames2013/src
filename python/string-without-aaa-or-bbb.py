class Solution:
    def strWithout3a3b(self, A: 'int', B: 'int', a="a", b="b") -> 'str':
        if B>A: return self.strWithout3a3b(B, A, "b", "a")
        if A>=2*B:
            return (a+a+b)*B+a*(A-2*B)
        else:
            return (a+a+b)*(A-B)+(a+b)*(2*B-A)

