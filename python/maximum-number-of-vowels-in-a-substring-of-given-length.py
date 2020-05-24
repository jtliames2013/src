class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        res, count=0, 0
        for i, c in enumerate(s):
            count+= c in 'aeiou'
            if i>=k: count-= s[i-k] in 'aeiou'
            if i>=k-1: res=max(res, count)
        return res

