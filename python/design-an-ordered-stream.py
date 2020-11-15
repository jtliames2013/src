class OrderedStream:

    def __init__(self, n: int):
        self.n=n
        self.data=[None]*n
        self.ptr=0

    def insert(self, id: int, value: str) -> List[str]:
        id-=1
        self.data[id]=value
        if self.ptr!=id:
            return[]
        else:
            while self.ptr<self.n and self.data[self.ptr]!=None: self.ptr+=1           
            return self.data[id:self.ptr]

# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)

