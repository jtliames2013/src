class Solution:
    def tribonacci(self, n: int) -> int:
        if n<2: return n
        a,b,c=0,0,1
        for i in range(2,n+1):
            d=a+b+c
            a=b
            b=c
            c=d
        return d
            
