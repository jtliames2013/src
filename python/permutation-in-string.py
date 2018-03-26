class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        m, n=len(s1), len(s2)
        d=collections.defaultdict(int)
        for c in s1: d[c]+=1
        curr=d.copy()
        
        l, r=0, 0
        while r<n:
            if s2[r] not in curr:
                r+=1
                l=r
                curr=d.copy()
            else:
                curr[s2[r]]-=1
                while curr[s2[r]]<0:
                    curr[s2[l]]+=1
                    l+=1
                if r-l+1==m: return True
                r+=1
        return False
