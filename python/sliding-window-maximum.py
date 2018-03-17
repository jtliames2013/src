class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        res=[]
        idx=collections.deque()
        for i,n in enumerate(nums):
            while len(idx)>0 and n>=nums[idx[-1]]:
                idx.pop()
            idx.append(i)
            if i-idx[0]==k: idx.popleft()
            if i>=k-1: res.append(nums[idx[0]])
                
        return res
            
        
