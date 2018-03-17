class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data, self.min=[], []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if len(self.min)==0 or x<=self.min[-1]: self.min.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if len(self.data)==0: return
        if self.min[-1]==self.data[-1]: self.min.pop()
        self.data.pop()

    def top(self):
        """
        :rtype: int
        """
        if len(self.data)==0: return -1
        return self.data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.min)==0: return -1
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
