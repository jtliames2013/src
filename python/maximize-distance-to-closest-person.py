class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        res, zeros, n=0, 0, len(seats)
        for i in range(n):
            if seats[i]==1: zeros=0
            else:
                zeros+=1
                res=max(res, int((zeros+1)/2))
        for i in range(n):
            if seats[i]==1: break
        res=max(res, i)
        for i in range(len(seats))[::-1]:
            if seats[i]==1: break
        res=max(res, n-1-i)
        return res
