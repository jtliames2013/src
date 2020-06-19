1. Lock
from threading import Lock

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock, self.bar_lock=Lock(), Lock()
        self.bar_lock.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:

        for i in range(self.n):
            self.foo_lock.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.bar_lock.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:

        for i in range(self.n):
            self.bar_lock.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.foo_lock.release()

2. Condition
from threading import Condition

class FooBar:
    def __init__(self, n):
        self.n = n
        self.cv=Condition()
        self.count=0

    def foo(self, printFoo: 'Callable[[], None]') -> None:

        for i in range(self.n):
            with self.cv:
                self.cv.wait_for(lambda: self.count%2==0)
                # printFoo() outputs "foo". Do not change or remove this line.
                printFoo()
                self.count+=1
                self.cv.notify_all()


    def bar(self, printBar: 'Callable[[], None]') -> None:

        for i in range(self.n):
            with self.cv:
                self.cv.wait_for(lambda: self.count%2==1)
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()
                self.count+=1
                self.cv.notify_all()

