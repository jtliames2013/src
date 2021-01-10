class Solution:
    def totalMoney(self, n: int) -> int:
        div, mod=n//7, n%7
        return sum(range(1, 8))*div+7*(div-1)*div//2+sum(range(div+1, div+1+mod))

