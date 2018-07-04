class Solution:
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        def dfs(start):
            if visited[start]!=0: return True if visited[start]==1 else False
            visited[start]=-1
            for neighbor in graph[start]:
                if not dfs(neighbor): return False
            
            visited[start]=1
            return True
            
        n=len(graph)
        visited=[0]*n
        res=[]
        for i in range(n):
            if dfs(i): res.append(i)
        
        return res
