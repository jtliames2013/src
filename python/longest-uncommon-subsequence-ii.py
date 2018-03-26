class Solution:
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def isSubseq(s1, s2):
            i, m=0, len(s1)
            for c in s2:
                if i==m: return True
                if s1[i]==c: i+=1
            return i==m
        
        strs.sort(key=len, reverse=True)
        for i, s1 in enumerate(strs):
            if all(not isSubseq(s1, s2) for j, s2 in enumerate(strs) if i!=j):
                return len(s1)            
        return -1
