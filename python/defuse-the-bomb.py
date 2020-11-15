class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n=len(code)
        res=[0]*n
        if k==0: return res
        start, end, sum=1, k, 0
        if k<0:
            k=-k
            start, end=n-k, n-1
        for i in range(start, end+1): sum+=code[i]
        for i in range(n):
            res[i]=sum
            sum-=code[start]
            start=(start+1)%n
            end=(end+1)%n
            sum+=code[end]
        return res

