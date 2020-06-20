from threading import Condition

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.cv = Condition()
        self.isZero = True
        self.count = 1
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n):
            with self.cv:
                self.cv.wait_for(lambda: self.isZero)
                printNumber(0)
                self.isZero=False
                self.cv.notify_all()
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n//2):
            with self.cv:
                self.cv.wait_for(lambda: not self.isZero and self.count%2==0)
                printNumber(self.count)
                self.isZero=True
                self.count+=1
                self.cv.notify_all()
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range((self.n+1)//2):
            with self.cv:
                self.cv.wait_for(lambda: not self.isZero and self.count%2==1)
                printNumber(self.count)
                self.isZero=True
                self.count+=1
                self.cv.notify_all()
        
