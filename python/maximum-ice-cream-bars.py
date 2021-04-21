class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        for i, v in enumerate(costs):
            if coins<v: return i
            coins-=v
        return len(costs)

