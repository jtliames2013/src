class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        m, n=len(candiesCount), len(queries)
        res=[False]*n
        sums=[0]*(m+1)
        for i in range(1, m+1):
            sums[i]=sums[i-1]+candiesCount[i-1]
        for i, q in enumerate(queries):
            favoriteType, favoriteDay, dailyCap=q[0], q[1], q[2]
            mn=sums[favoriteType]//dailyCap
            mx=sums[favoriteType+1]-1
            if mn<=favoriteDay<=mx:
                res[i]=True
        return res

