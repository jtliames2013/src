class Solution:
    def getProbability(self, balls: List[int]) -> float:
        def dfs(i, sum1, sum2, color1, color2):
            if sum1>self.sum/2 or sum2>self.sum/2: return
            if i==len(balls):
                p1, p2=permutation(sum1, left), permutation(sum2, right)
                self.total+=p1*p2
                self.good+=p1*p2*(color1==color2)
                return
            for j in range(balls[i]+1):
                left[i], right[i]=j, balls[i]-j
                dfs(i+1, sum1+j, sum2+balls[i]-j, color1+(j!=0), color2+(j!=balls[i]))
        self.good, self.total, self.sum=0, 0, sum(balls)
        left, right={}, {}
        permutation=lambda s, d: math.factorial(s)/reduce(operator.mul, [math.factorial(i) for i in d.values()])
        dfs(0, 0, 0, 0, 0)
        return self.good/self.total

