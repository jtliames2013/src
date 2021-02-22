class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res, m, n, i="", len(word1), len(word2), 0
        while i<m and i<n:
            res+=word1[i]+word2[i]
            i+=1
        res+=word1[i:] if m>n else word2[i:]
        
        return res

