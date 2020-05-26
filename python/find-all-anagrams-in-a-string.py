class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res, m, n, l, r=[], len(s), len(p), 0, 0
        count=collections.Counter(p)
        curr=deepcopy(count)
        while r<m:
            if s[r] not in count:
                curr=deepcopy(count)
                r+=1
                l=r
            else:
                curr[s[r]]-=1
                while curr[s[r]]<0:
                    curr[s[l]]+=1
                    l+=1
                if r-l+1==n: res.append(l)
                r+=1
        return res

