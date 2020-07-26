class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        n=len(s)
        res=['']*n
        for i, v in enumerate(indices):
            res[v]=s[i]
        return ''.join(res)
