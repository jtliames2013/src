class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        m, n=len(s), len(t)
        if m!=n: return False
        d=collections.defaultdict(int)
        for i in range(m):
            cnt=(ord(t[i])-ord(s[i])+26)%26
            if cnt==0: continue
            d[cnt]+=1
            if (d[cnt]-1)*26+cnt>k: return False
        return True

