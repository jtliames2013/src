class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp=[True]+[False]*len(s)
        for i in range(1, len(s)+1):
            for w in wordDict:
                if i-len(w)>=0 and w==s[i-len(w):i] and dp[i-len(w)]==True:
                    dp[i]=True
                    break
        return dp[len(s)]
