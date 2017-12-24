class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n=len(cost)        
        a=0; b=cost[0]
        for i in range(1,n):
            c=min(a,b)+cost[i]
            a=b
            b=c
        return min(a,b)
