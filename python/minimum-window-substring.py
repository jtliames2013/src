class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l, total, minLen, start=0, len(t), float('inf'), 0
        d=collections.Counter(t)
        
        for r in range(len(s)):
            if s[r] in d:
                d[s[r]]-=1
                if d[s[r]]>=0: total-=1
            if total==0:
                while total==0:
                    if s[l] in d:
                        d[s[l]]+=1
                        if d[s[l]]>0: total+=1
                    l+=1
                if minLen>r-l+2:
                    minLen=r-l+2
                    start=l-1
        return s[start:start+minLen] if minLen!=float('inf') else ""
    
