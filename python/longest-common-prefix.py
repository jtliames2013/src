class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs: return ""
        res=min(strs, key=len)
        for i, v in enumerate(res):
            for s in strs:
                if v!=s[i]: return res[:i]
        return res

