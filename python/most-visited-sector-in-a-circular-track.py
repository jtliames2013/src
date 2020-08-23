class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        return range(rounds[0], rounds[-1]+1) or list(range(1, rounds[-1]+1))+list(range(rounds[0], n+1))

