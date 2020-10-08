class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic=collections.defaultdict(int)
        res, l, r, n=0, 0, 0, len(s)
        while r<n:
            if s[r] in dic:
                res=max(res, r-l)
                while l<=dic[s[r]]:
                    dic.pop(s[l])
                    l+=1
            dic[s[r]]=r
            r+=1
        res=max(res, r-l)
        return res

