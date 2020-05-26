class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res, i, j, num="", len(num1)-1, len(num2)-1, 0
        while i>=0 or j>=0:
            if i>=0:
                num+=ord(num1[i])-ord('0')
                i-=1
            if j>=0:
                num+=ord(num2[j])-ord('0')
                j-=1
            res+=str(num%10)
            num//=10
            
        if num: res+=str(num)
        return res[::-1]

