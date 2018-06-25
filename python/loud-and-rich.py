class Solution:
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """
        def dfs(person):
            if res[person]>=0: return
            res[person]=person
            for neighbor in m[person]:
                dfs(neighbor)
                if quiet[res[person]]>quiet[res[neighbor]]: res[person]=res[neighbor]
                    
        m=collections.defaultdict(set)
        for i, j in richer: m[j].add(i)
        res=[-1]*len(quiet)
        for i in range(len(quiet)): dfs(i)
        
        return res
