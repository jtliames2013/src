ass Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:        
        res, n=0, len(costs)
        costs=sorted(costs, key=lambda v: v[0]-v[1])
        for i in range(n//2):
            res+=costs[i][0]+costs[n-1-i][1]
        return res

