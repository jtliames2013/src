1.
class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r=0, len(s)-1
        while l<r:
            if s[l]!=s[r]:
                one, two=s[l:r], s[l+1:r+1]
                return one==one[::-1] or two==two[::-1]
            l, r=l+1, r-1
        return True
  
2.
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def dfs(s, l, r, delete):
            while l<r:
                if s[l]!=s[r]:
                    if delete==0: return False
                    return dfs(s, l+1, r, 0) or dfs(s, l, r-1, 0)
                else:
                    l, r=l+1, r-1
            return True
        return dfs(s, 0, len(s)-1, 1)

