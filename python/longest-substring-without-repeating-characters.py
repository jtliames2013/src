class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        pos = {}
        longest = 0
        if len(s) == 0:
            return longest
        l = 0
        r = 0
        for r in range(len(s)):
            if s[r] in pos:
                longest = max(longest, r - l)
                for i in range(l, pos[s[r]]):
                    del pos[s[i]]
                l = pos[s[r]] + 1
            pos[s[r]] = r
        longest = max(longest, r - l + 1)
        return longest
