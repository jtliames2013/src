class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        res=[]
        for i in range(1, isqrt(n)+1):
            if n%i==0:
                k-=1
                if k==0: return i
                if i*i!=n: res.append(i)
        
        size=len(res)
        return n//res[size-k] if k<=size else -1

