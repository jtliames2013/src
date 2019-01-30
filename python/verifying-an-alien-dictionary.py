class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        d={c: i for i, c in enumerate(order)}
        words=[[d[c] for c in w] for w in words]
        return all(words[i]<=words[i+1] for i in range(len(words)-1))

