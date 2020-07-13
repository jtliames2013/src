class Solution:
    def minInteger(self, num: str, k: int) -> str:
        n=len(num)
        if k<=0: return num
        if k>=n*(n+1)//2: return ''.join(sorted(num))
        
        for i in range(10):
            pos=num.find(str(i))
            if 0<=pos<=k:
                return num[pos]+self.minInteger(num[:pos]+num[pos+1:], k-pos)
        return num
        
