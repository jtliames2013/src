class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        def dfs(start):
            if start==m: return True
            if res[start]>0:
                return dfs(start+1)
            
            for i in range(n-1, -1, -1):
                if used[i] or (i>0 and (start+i+1>=m or res[start+i+1]>0)): continue
                used[i]=True
                res[start]=i+1
                if i>0: res[start+i+1]=i+1
                if dfs(start+1): return True
                res[start]=0
                if i>0: res[start+i+1]=0
                used[i]=False
            
            return False
            
        m=2*n-1
        res=[0]*m
        used=[False]*n
        dfs(0)
        
        return res

