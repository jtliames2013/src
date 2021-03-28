class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        res, i, n='', 0, len(s)
        d={k:v for k, v in knowledge}
        while i<n:
            if s[i]=='(':
                j=i
                while j<n and s[j]!=')': j+=1
                res+=d[s[i+1:j]] if s[i+1:j] in d else '?'
                i=j+1
            else:
                res+=s[i]
                i+=1
        return res

