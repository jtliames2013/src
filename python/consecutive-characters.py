class Solution:
    def maxPower(self, s: str) -> int:
        return max(len(list(g)) for k, g in itertools.groupby(s))

