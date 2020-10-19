class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.int=[]
        self.out=[]
        self.front=0

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if len(self.int)==0: self.front=x
        self.int.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.empty(): return
        if len(self.out)==0:
            while self.int:
                self.out.append(self.int.pop())
        return self.out.pop()
            

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.empty(): return -1
        if len(self.int)>0: return self.front
        else: return self.out[-1]        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.int)==0 and len(self.out)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

