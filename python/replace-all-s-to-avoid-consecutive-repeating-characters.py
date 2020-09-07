class Solution:
    def modifyString(self, s: str) -> str:
        n, res=len(s), []
        for i, v in enumerate(s):
            if v!='?': ch=v
            else:
                ch='a'
                if i>0 and res[-1]==ch: ch='b'
                if i<n-1 and s[i+1]==ch: ch='c'
            res.append(ch)
        return ''.join(res)

