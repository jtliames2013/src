class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.append(h)
        verticalCuts.append(w)
        horizontalCuts.sort()
        verticalCuts.sort()
        maxh, maxw=horizontalCuts[0], verticalCuts[0]
        for i in range(1, len(horizontalCuts)):
            maxh=max(maxh, horizontalCuts[i]-horizontalCuts[i-1])
        for i in range(1, len(verticalCuts)):
            maxw=max(maxw, verticalCuts[i]-verticalCuts[i-1])
        return maxh*maxw%1000000007

