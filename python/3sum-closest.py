class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res, diff=0, sys.maxsize
        nums.sort()
        
        for i in range(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]: continue
            l, r=i+1, len(nums)-1
            while l<r:
                s=nums[i]+nums[l]+nums[r]
                if s==target: return s
                elif s<target:
                    if diff>target-s:
                        diff=target-s
                        res=s
                    l+=1
                else:
                    if diff>s-target:
                        diff=s-target
                        res=s
                    r-=1
        
        return res
