class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        res, n=nums[-1], len(nums)
        dq=deque([n-1])
        for i in range(n-2, -1, -1):
            res=nums[i]+nums[dq[0]]            
            while dq and res>nums[dq[-1]]: dq.pop()
            dq.append(i)
            if dq[0]-i==k: dq.popleft()
            nums[i]=res
        return res

