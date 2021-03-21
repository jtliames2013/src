class Solution:
    def secondHighest(self, s: str) -> int:
        mx1, mx2=-1, -1
        for c in s:
            if c.isnumeric():
                num=ord(c)-ord('0')
                if num>mx1: 
                    mx2=mx1
                    mx1=num
                elif num<mx1 and num>mx2:
                    mx2=num
                
        return mx2

