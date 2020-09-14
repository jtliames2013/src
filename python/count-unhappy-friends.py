class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        idx=[collections.defaultdict(int) for i in range(n)]
        for i in range(n):
            for j, v in enumerate(preferences[i]):
                idx[i][v]=j
        
        par=[0]*n
        for p in pairs:
            par[p[0]]=p[1]
            par[p[1]]=p[0]
            
        res=0
        for i in range(n):
            for j in preferences[i]:
                if idx[i][j]<idx[i][par[i]] and idx[j][i]<idx[j][par[j]]:
                    res+=1
                    break
        
        return res
