class Solution:

    def __init__(self, N, blacklist):
        """
        :type N: int
        :type blacklist: List[int]
        """
        self.d=collections.defaultdict(int)
        self.size=N-len(blacklist)
        for b in blacklist: self.d[b]
        k=N-1
        for b in blacklist:
            if b<self.size:
                while k in self.d: k-=1
                self.d[b]=k
                k-=1

    def pick(self):
        """
        :rtype: int
        """
        v=random.randint(0, self.size-1)
        if v in self.d: v=self.d[v]
        return v


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
