class Solution:
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        time=[float(target-p)/s for p, s in sorted(zip(position, speed))]
        res, n=len(position), 0
        for t in time[::-1]:
            if t<=n: res-=1
            else: n=t
        return res
        
