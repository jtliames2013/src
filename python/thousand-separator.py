class Solution:
    def thousandSeparator(self, n: int) -> str:
        if n==0: return "0"
        res, i=[], 0
        while n>0:
            if i%3==0 and i>0: res.append('.')
            res.append(chr(n%10+ord('0')))
            n//=10
            i+=1
        return ''.join(reversed(res))

