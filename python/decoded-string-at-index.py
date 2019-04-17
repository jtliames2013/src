class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        l=0
        for i,c in enumerate(S):
            l=int(c)*l if c.isdigit() else l+1
            if K<=l: break

        while i>=0:
            if S[i].isdigit():
                l/=int(S[i])
                K%=l
            elif K==l or K==0:
                return S[i]
            else:
                l-=1
            i-=1
