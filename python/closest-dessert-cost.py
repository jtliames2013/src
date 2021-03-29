class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        def dfs(curr, i):
            nonlocal res, minDiff
            diff=abs(target-curr)
            if diff<minDiff or (diff==minDiff and res>curr):
                minDiff=diff
                res=curr
            if i==len(toppingCosts) or curr>target: return

            dfs(curr, i+1)
            dfs(curr+toppingCosts[i], i+1)
            dfs(curr+toppingCosts[i]*2, i+1)
            
        res, minDiff=0, float('inf')
        for b in baseCosts:
            dfs(b, 0)
        return res

