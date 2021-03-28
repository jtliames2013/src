class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        s=''.join(c if c.isdigit() else ' ' for c in word)
        return len(collections.Counter(map(int, s.split())))

