class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        res, n=0, len(arr)
        for i in range(n):
            for j in range(i+1, n):
                if abs(arr[i]-arr[j])<=a:
                    for k in range(j+1, n):
                        if abs(arr[i]-arr[k])<=c and abs(arr[j]-arr[k])<=b:
                            res+=1
        return res
