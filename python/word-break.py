1.
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict=set(wordDict)
        n=len(s)
        dp=[True]+[False]*n
        for i in range(1, n+1):
            for j in range(0, i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i]=True
                    break
        return dp[n]

2.
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict=set(wordDict)
        n=len(s)
        dp=[True]+[False]*n
        for i in range(1, n+1):
            for w in wordDict:
                l=len(w)
                if i>=l and w==s[i-l:i] and dp[i-l]==True:
                    dp[i]=True
                    break
        return dp[n]

