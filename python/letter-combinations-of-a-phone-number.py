class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(digits, start, s):
            if start==len(digits):
                res.append(s)
                return
            for c in list(d[digits[start]]):
                dfs(digits, start+1, s+c)
                
        if not digits: return []
        d = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
             '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        res=[]
        dfs(digits, 0, "")
        return res

