class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        d=collections.defaultdict(int)
        for c in s: d[c]+=1
        for c in t:
            d[c]-=1
            if d[c]<0: return c
