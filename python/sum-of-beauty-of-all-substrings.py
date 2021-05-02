class Solution:
    def beautySum(self, s: str) -> int:
        res, n=0, len(s)
        for i in range(n):
            cnt=[0]*26
            for j in range(i, -1, -1):
                cnt[ord(s[j])-ord('a')]+=1
                res+=max(cnt)-min(c for c in cnt if c)
        return res

