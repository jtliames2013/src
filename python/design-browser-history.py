class BrowserHistory:

    def __init__(self, homepage: str):
        self.back_hist, self.forward_hist=[], []
        self.back_hist.append(homepage)

    def visit(self, url: str) -> None:
        self.forward_hist.clear()
        self.back_hist.append(url)

    def back(self, steps: int) -> str:
        while steps>0 and len(self.back_hist)>1:
            self.forward_hist.append(self.back_hist.pop())
            steps-=1
        return self.back_hist[-1]
            
    def forward(self, steps: int) -> str:
        while steps>0 and self.forward_hist:
            self.back_hist.append(self.forward_hist.pop())
            steps-=1
        return self.back_hist[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

