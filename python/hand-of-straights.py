class Solution:
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        c=collections.Counter(hand)
        while c:
            k=sorted(c)[0]
            for i in range(W):
                if k not in c: return False
                c[k]-=1
                if c[k]==0: del c[k]
                k+=1
        return True
