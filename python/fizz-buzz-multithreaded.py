from threading import Condition

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.cv = Condition()
        self.count = 1
        
    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            with self.cv:
                self.cv.wait_for(lambda: self.count>self.n or (self.count%3==0 and self.count%5!=0))
                if self.count>self.n: break
                printFizz()
                self.count+=1
                self.cv.notify_all()    	

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True:
            with self.cv:
                self.cv.wait_for(lambda: self.count>self.n or (self.count%3!=0 and self.count%5==0))
                if self.count>self.n: break
                printBuzz()
                self.count+=1
                self.cv.notify_all()    	

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            with self.cv:
                self.cv.wait_for(lambda: self.count>self.n or (self.count%3==0 and self.count%5==0))
                if self.count>self.n: break
                printFizzBuzz()
                self.count+=1
                self.cv.notify_all()    	        

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            with self.cv:
                self.cv.wait_for(lambda: self.count>self.n or (self.count%3!=0 and self.count%5!=0))
                if self.count>self.n: break
                printNumber(self.count)
                self.count+=1
                self.cv.notify_all()
                
