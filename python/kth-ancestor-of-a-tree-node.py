class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.maxSteps=16
        self.ancestors=[dict(enumerate(parent))]
        for i in range(self.maxSteps):
            cur=self.ancestors[-1]
            new={}
            for k in cur:
                if cur[k] in cur:
                    new[k]=cur[cur[k]]
            self.ancestors.append(new)

    def getKthAncestor(self, node: int, k: int) -> int:
        step=self.maxSteps
        while k>0 and node!=-1:
            if k>=(1<<step):
                node=self.ancestors[step].get(node, -1)
                k-=(1<<step)
            else:
                step-=1
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)

