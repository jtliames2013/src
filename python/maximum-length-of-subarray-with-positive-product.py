class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        res, n=0, len(nums)
        start, first, cnt=-1, -1, 0
        for i in range(n):
            if nums[i]==0:
                start, first, cnt=i, -1, 0
            else:
                if nums[i]<0:
                    if first==-1: first=i
                    cnt+=1
                if cnt%2==0: res=max(res, i-start)
                else: res=max(res, i-first)
        return res

