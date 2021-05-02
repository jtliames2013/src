class Solution:
    def replaceDigits(self, s: str) -> str:
        return ''.join(s[i] if i%2==0 else chr(ord(s[i-1])+int(s[i])) for i in range(len(s)))

