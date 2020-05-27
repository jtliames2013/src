class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        sums, dic=0, {0: -1}
        for i, v in enumerate(nums):
            sums+=v
            if k!=0: sums%=k
            if sums in dic:
                if i-dic[sums]>=2: return True
            else: dic[sums]=i
        return False
        
