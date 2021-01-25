class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        m, n=len(a), len(b)
        cnt1, cnt2=Counter(ord(c)-ord('a') for c in a), Counter(ord(c)-ord('a') for c in b)
        res=m+n-max((cnt1+cnt2).values())
        for i in range(25):
            # all chars in a is less than or equal to the current char
            # all chars in b is greater than the current char
            res=min(res, m-cnt1[i]+cnt2[i])
            res=min(res, n-cnt2[i]+cnt1[i])
            cnt1[i+1]+=cnt1[i]
            cnt2[i+1]+=cnt2[i]
        return res

