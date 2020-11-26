class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        res, i=['a']*n, n-1
        k-=n        
        while k>0:
            num=min(k, 25)
            res[i]=chr(ord('a')+num)
            k-=num
            i-=1
        return ''.join(res)

