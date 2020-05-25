class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(output, candidates, target, start):
            if target==0: 
                res.append(output[:])
                return
            
            for i in range(start, len(candidates)):
                if target>=candidates[i]:
                    output.append(candidates[i])
                    dfs(output, candidates, target-candidates[i], i)
                    output.pop()
                    
        res, output=[], []
        dfs(output, candidates, target, 0)
        return res

