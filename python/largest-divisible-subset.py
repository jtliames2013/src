1.
class Solution:
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums)==0: return []
        nums.sort()
        dp=[1]*len(nums)
        index=[-1]*len(nums)
        
        maxdp, maxindex=1, 0
        for i, n in enumerate(nums):
            for j in range(i):
                if nums[i]%nums[j]==0 and dp[i]<dp[j]+1:
                    dp[i]=dp[j]+1
                    index[i]=j
            
            if maxdp<dp[i]:
                maxdp=dp[i]
                maxindex=i
                
        res=[]
        i=maxindex
        while i!=-1:
            res.append(nums[i])
            i=index[i]
            
        return res

2.
class Solution:
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        mp={-1: set()}
        for n in sorted(nums):
            mp[n]= max((mp[k] for k in mp if n%k==0), key=len) | {n}
            
        return list(max(mp.values(), key=len))
