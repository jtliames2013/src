class ExamRoom:

    def __init__(self, N):
        """
        :type N: int
        """
        self.N, self.s=N, []

    def seat(self):
        """
        :rtype: int
        """
        if not self.s: res=0
        else:
            d, res=self.s[0], 0
            for a, b in zip (self.s[:-1], self.s[1:]):
                if int((b-a)/2)>d:
                    d, res=int((b-a)/2), int((a+b)/2)
            if self.N-1-self.s[-1]>d:
                res=self.N-1
        bisect.insort(self.s, res)
        return res

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """        
        self.s.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
