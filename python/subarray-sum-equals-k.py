class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res, sums, dic=0, 0, {}
        dic[0]=1
        for _, v in enumerate(nums):
            sums+=v
            if sums-k in dic: res+=dic[sums-k]
            dic[sums]=dic.get(sums, 0)+1
        return res

