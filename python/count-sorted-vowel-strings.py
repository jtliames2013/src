1.
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp=[1]*5
        for i in range(n-1):
            for j in range(1, 5):
                dp[j]+=dp[j-1]
        return sum(dp)

2.
Add 4 boundary in any position, n+4 char, 4 boundary char
class Solution:
    def countVowelStrings(self, n: int) -> int:
        return comb(n+4, 4)
