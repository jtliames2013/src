class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:            
        tasks.sort(key=lambda t: t[0]-t[1])
        res, curr=0, 0
        for a, m in tasks:
            if curr<m:
                res+=m-curr
                curr=m
            curr-=a
        return res

