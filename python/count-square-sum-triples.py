class Solution:
    def countTriples(self, n: int) -> int:
        res=0
        for i in range(1, n+1):
            for j in range(i, n+1):
                sum=i*i+j*j
                if sum>n*n: break
                c=int(sqrt(sum))
                if c*c==sum: res+=2
        return res

