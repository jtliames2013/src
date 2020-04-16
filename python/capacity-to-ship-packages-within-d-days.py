class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        l, r=max(weights), sum(weights)
        while l<r:
            curr, days, mid=0, 1, l+(r-l)//2
            for w in weights:
                if curr+w>mid:
                    days+=1
                    curr=0
                curr+=w
                
            if days<=D: r=mid
            else:l=mid+1
            
        return r

