from threading import Condition

class H2O:
    def __init__(self):
        self.h, self.o=0, 0
        self.cv=Condition()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda: self.h<2*self.o+2)
            # releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen()
            self.h+=1
            self.cv.notify_all()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.cv:
            self.cv.wait_for(lambda: self.o<=self.h//2)
            # releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen()
            self.o+=1
            self.cv.notify_all()

