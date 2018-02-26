class Solution:
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """        
        mp=collections.defaultdict(set)
        for u, v in edges:
            mp[u].add(v)
            mp[v].add(u)
        
        res=[i for i in range(n) if len(mp[i])<=1]
        while n>2:
            nxt=[]
            for i in res:
                for v in mp[i]:
                    mp[v].remove(i)
                    if len(mp[v])==1: nxt.append(v)
            
            n-=len(res)
            res=nxt
        
        return res
        
