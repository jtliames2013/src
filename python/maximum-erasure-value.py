class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        res, sum, l, n, st=0, 0, 0, len(nums), set()
        for r in range(n):
            while nums[r] in st:
                sum-=nums[l]
                st.remove(nums[l])
                l+=1
            
            sum+=nums[r]
            st.add(nums[r])
            res=max(res, sum)
                
        return res
        
