class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def dfs(start, last, count, delete):
            if delete<0: return float('inf')
            if start==len(s): return 0
            if s[start]==last:
                # no need to delete in the middle since it is the same 
                # if we delete at the beginning
                inc=1 if count==1 or count==9 or count==99 else 0
                return inc+dfs(start+1, last, count+1, delete)
            else:
                return min(dfs(start+1, last, count, delete-1), 1+dfs(start+1, s[start], 1, delete))
        return dfs(0, '', 0, k)

