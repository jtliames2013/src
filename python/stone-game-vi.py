class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        s=sorted(zip(aliceValues, bobValues), key=sum, reverse=True)
        print(s)
        a=sum(i for i, j in s[::2])
        b=sum(j for i, j in s[1::2])
        if a>b: return 1
        elif a<b: return -1
        else: return 0

