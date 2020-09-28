class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        def dfs(start, num):
            nonlocal res
            if b.count(0)==n:
                res=max(res, num)

            for i in range(start, len(requests)):
                b[requests[i][0]]-=1
                b[requests[i][1]]+=1
                dfs(i+1, num+1)
                b[requests[i][0]]+=1
                b[requests[i][1]]-=1
        
        mask,b, res=0, [0]*n, float('-inf')
        dfs(0, 0)
        return res

