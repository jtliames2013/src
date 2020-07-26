class Solution:
    def minFlips(self, target: str) -> int:
        res, state=0, '0'
        for c in target:
            if c!=state:
                res+=1
                state='1' if state=='0' else '0'
        return res

