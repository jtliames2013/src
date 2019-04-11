ass Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        l, r=1, max(piles)
        while l<r:
            mid=(l+r)//2
            s=0
            for p in piles: s+=(p+mid-1)//mid
            if s>H: l=mid+1
            else: r=mid
        return l
