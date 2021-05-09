class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        n, base=101, 1950
        pop=[0]*n
        for l in logs:
            pop[l[0]-base]+=1
            pop[l[1]-base]-=1
        res, mx=0, pop[0]     
        for i in range(1, n):
            pop[i]+=pop[i-1]
            if pop[i]>mx:
                mx=pop[i]
                res=i
        return res+base

