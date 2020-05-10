class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        res, xor=0, 0
        d={0: [1, -1]}
        for i, v in enumerate(arr):
            xor ^= v
            if xor not in d: d[xor]=[0, 0]
            count=d[xor][0]
            totalIndex=d[xor][1]
            res+=count*(i-1)-totalIndex
            d[xor]=[count+1, totalIndex+i]
            
        return res

