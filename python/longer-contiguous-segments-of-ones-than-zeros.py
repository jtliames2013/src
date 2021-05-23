class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        mx0, mx1, cnt0, cnt1=0, 0, 0, 0
        for c in s:
            if c=='0':
                cnt1=0
                cnt0+=1
            else:
                cnt0=0
                cnt1+=1
            mx0=max(mx0, cnt0)
            mx1=max(mx1, cnt1)
        return mx1>mx0

