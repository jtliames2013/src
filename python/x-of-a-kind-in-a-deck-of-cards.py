import functools
import fractions

class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        return functools.reduce(fractions.gcd, collections.Counter(deck).values())>1
