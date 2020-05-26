class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res, i, j, num="", len(a)-1, len(b)-1, 0
        while i>=0 or j>=0:
            if i>=0:
                num+=a[i]=='1'
                i-=1
            if j>=0:
                num+=b[j]=='1'
                j-=1
            res+=str(num%2)
            num//=2
        
        if num: res+=str(num)
        return res[::-1]

