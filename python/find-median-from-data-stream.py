class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.large, self.small=[], []

    def addNum(self, num: int) -> None:
        if not self.small or num<-self.small[0]: heappush(self.small, -num)
        else: heappush(self.large, num)
        
        if len(self.small)>len(self.large)+1:
            heappush(self.large, -heappop(self.small))
        elif len(self.small)+1<len(self.large):
            heappush(self.small, -heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small)==len(self.large):
            return 0 if len(self.small)==0 else (-self.small[0]+self.large[0])/2
        else:
            return -self.small[0] if len(self.small)>len(self.large) else self.large[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
