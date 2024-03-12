class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.site = 0
        self.top = 0

    def visit(self, url: str) -> None:
        while self.site < self.top:
            self.history.pop()
            self.top -= 1
        self.history.append(url)
        self.site += 1
        self.top += 1

    def back(self, steps: int) -> str:
        self.site -= steps
        if self.site < 0:
            self.site = 0
        return self.history[self.site]

    def forward(self, steps: int) -> str:
        self.site += steps
        if self.site > self.top:
            self.site = self.top
        return self.history[self.site]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
