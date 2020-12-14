1.
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        res, count=0, collections.Counter(nums)
        for i in count:
            j=k-i
            if i==j: res+=count[i]//2
            else:
                if j in count:
                    mn=min(count[i], count[j])
                    count[i]-=mn
                    count[j]-=mn
                    res+=mn
        return res

2.
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        res, n=0, len(nums)
        nums.sort()
        l, r=0, n-1
        while l<r:
            if nums[l]+nums[r]==k:
                res+=1
                l, r=l+1, r-1
            elif nums[l]+nums[r]<k:
                l+=1
            else:
                r-=1

        return res

