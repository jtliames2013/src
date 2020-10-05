class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cand, cnt=0, 0
        for n in nums:
            if n==cand:
                cnt+=1
            elif cnt==0:
                cand=n
                cnt+=1
            else:
                cnt-=1
        return cand

