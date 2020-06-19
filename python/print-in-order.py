1. Lock
from threading import Lock

class Foo:
    def __init__(self):
        self.lock1, self.lock2=Lock(), Lock()
        self.lock1.acquire()
        self.lock2.acquire()


    def first(self, printFirst: 'Callable[[], None]') -> None:

        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.lock1.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.lock1:
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
        self.lock2.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.lock2:
            # printThird() outputs "third". Do not change or remove this line.
            printThird()

2. Condition
from threading import Condition

class Foo:
    def __init__(self):
        self.cv=Condition()
        self.count=0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        with self.cv:
            # printFirst() outputs "first". Do not change or remove this line.
            printFirst()
            self.count+=1
            self.cv.notify_all()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda: self.count==1)
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
            self.count+=1
            self.cv.notify_all()


    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda: self.count==2)
            # printThird() outputs "third". Do not change or remove this line.
            printThird()

