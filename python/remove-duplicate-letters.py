class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        res=[]
        d=collections.defaultdict(int)        
        visited=set()
        for c in s: d[c]+=1
        
        for c in s:
            d[c]-=1
            if c not in visited:
                while len(res)>0 and res[-1]>c and d[res[-1]]>0:
                    visited.remove(res[-1])
                    res.pop()                    
                res.append(c)
                visited.add(c)                    
        
        return ''.join(res)
