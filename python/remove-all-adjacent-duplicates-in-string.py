class Solution:
    def removeDuplicates(self, S: str) -> str:
        res=[]
        for c in S:
            if not res or res[-1]!=c: res.append(c)
            else: res.pop()
        return "".join(res)
