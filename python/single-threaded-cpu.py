class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:        
        res, pq, end, i, n=[], [], 0, 0, len(tasks)
        tasks=sorted([[t[0], t[1], i] for i, t in enumerate(tasks)])
        while len(res)<n:
            while i<n and tasks[i][0]<=end:
                heappush(pq, [tasks[i][1], tasks[i][2]])
                i+=1
            if len(pq)==0:
                end=tasks[i][0]
            else:
                p, idx=heappop(pq)
                res.append(idx)
                end+=p
        
        return res

