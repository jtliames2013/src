class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(output, start, k):
            if k==0:
                res.append(output[:])
                return
            
            for i in range(start, n-k+1):
                output.append(i+1)
                dfs(output, i+1, k-1)
                output.pop()
                
        res, output=[], []
        dfs(output, 0, k)
        return res

