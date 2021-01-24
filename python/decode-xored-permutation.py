class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n=len(encoded)+1
        res, xor=[0]*n, 0
        for i in range(1, n+1):
            xor^=i
            if i<n-1 and i%2==1:
                xor^=encoded[i]
        res[0]=xor
        for i in range(1, n):
            res[i]=res[i-1]^encoded[i-1]
        return res

