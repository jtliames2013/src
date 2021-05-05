class Solution:
    def splitString(self, s: str) -> bool:
        def dfs(start, prev, cnt):
            if start==n: return cnt>1
            for i in range(start, n):
                num=int(s[start:i+1])
                if prev<0 or num==prev-1:
                    res=dfs(i+1, num, cnt+1)
                    if res: return True
            
            return False
        
        n=len(s)
        return dfs(0, -1, 0)

