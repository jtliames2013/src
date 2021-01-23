class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        res,n=0, len(nums)
        dic=defaultdict(int)
        for i in range(n):
            for j in range(i+1, n):
                dic[nums[i]*nums[j]]+=1
        for v in dic.values():
            res+=8*comb(v, 2)
        return res

