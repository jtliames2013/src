class Fancy:

    def __init__(self):
        self.nums=[]
        self.add=[0]
        self.mul=[1]
        self.mod=10**9+7

    def append(self, val: int) -> None:
        self.nums.append(val)
        self.add.append(self.add[-1])
        self.mul.append(self.mul[-1])
        
    def addAll(self, inc: int) -> None:
        self.add[-1]+=inc

    def multAll(self, m: int) -> None:
        self.add[-1]=self.add[-1]*m%self.mod
        self.mul[-1]=self.mul[-1]*m%self.mod

    def getIndex(self, idx: int) -> int:
        if idx>=len(self.nums):
            return -1
        inverse=pow(self.mul[idx], -1, self.mod)
        m=self.mul[-1]*inverse
        inc=self.add[-1]-self.add[idx]*m
        return (self.nums[idx]*m+inc)%self.mod

# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)

