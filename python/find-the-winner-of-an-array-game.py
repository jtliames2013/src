class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        res, cnt, n=arr[0], 0, len(arr)
        for i in range(1, n):
            if res<arr[i]:
                res=arr[i]
                cnt=0
            cnt+=1
            if cnt==k: break
        return res

