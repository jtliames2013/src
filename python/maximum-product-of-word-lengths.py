class Solution:
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        d=collections.defaultdict(int)
        for w in words:
            num=0
            for c in set(w):
                num|=(1<<(ord(c)-ord('a')))
            d[num]=max(d[num], len(w))
        
        return max([d[i]*d[j] for i in d for j in d if not i&j] or [0])
