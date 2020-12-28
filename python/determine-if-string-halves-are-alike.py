class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        def isVowel(c):
            return c in {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        
        a, b, i, j=0, 0, 0, len(s)-1
        while i<j:
            if isVowel(s[i]): a+=1
            if isVowel(s[j]): b+=1
            i+=1
            j-=1
        return a==b

