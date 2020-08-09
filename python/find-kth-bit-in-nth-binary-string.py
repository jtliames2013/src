class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        l, flip=2**n-1, 0
        while n>1:
            if k==l//2+1: return str(1-flip)
            if k>l//2:
                k=l-k+1
                flip^=1
            l//=2
            n-=1
        return str(flip)

