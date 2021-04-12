class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        for i, v in enumerate(s):
            if v==' ': k-=1
            if k==0: return s[:i]
        return s

