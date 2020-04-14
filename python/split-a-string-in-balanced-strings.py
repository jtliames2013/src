class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res, cnt=0, 0
        for c in s:
            cnt+=1 if c=='L' else -1
            if cnt==0: res+=1
        
        return res

