class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return s
        longest = left = right = 0
        for i in range(len(s)):
            for j in range(2):
                if j == 0:
                    l = r = i
                else:
                    l = i
                    r = i + 1
                while l >= 0 and r < len(s) and s[l] == s[r]:
                    l -= 1
                    r += 1
                if longest < r-l-1:
                    longest = r-l-1
                    left = l+1
                    right = r-1
        
        return s[left: right+1]
        
