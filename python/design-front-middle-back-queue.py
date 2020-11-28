class FrontMiddleBackQueue:

    def __init__(self):
        self.q=[]
        

    def pushFront(self, val: int) -> None:
        self.q.insert(0, val)

    def pushMiddle(self, val: int) -> None:
        l=len(self.q)
        self.q.insert(l//2, val)

    def pushBack(self, val: int) -> None:
        self.q.append(val)

    def popFront(self) -> int:
        if len(self.q)==0: return -1
        return self.q.pop(0)

    def popMiddle(self) -> int:
        if len(self.q)==0: return -1
        l=len(self.q)
        return self.q.pop((l-1)//2)

    def popBack(self) -> int:
        if len(self.q)==0: return -1
        return self.q.pop()


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()

