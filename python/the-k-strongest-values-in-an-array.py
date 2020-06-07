class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        res, l, r, m=[], 0, len(arr)-1, arr[(len(arr)-1)//2]
        for _ in range(k):
            if abs(arr[l]-m)>abs(arr[r]-m):
                res.append(arr[l])
                l+=1
            else:
                res.append(arr[r])
                r-=1
        return res

