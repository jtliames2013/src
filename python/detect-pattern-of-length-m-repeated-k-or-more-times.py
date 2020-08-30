class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        n, cnt=len(arr), 0
        for i in range(n-m):
            if arr[i]!=arr[i+m]: cnt=0
            else: cnt+=1
            if cnt==(k-1)*m: return True
        return False

