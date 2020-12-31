class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int) -> int:
        n, trip, r, last=len(boxes), 0, 0, 0
        dp=[0] + [float('inf')]*n
        
        for l in range(n):
            while r<n and maxBoxes>0 and maxWeight>=boxes[r][1]:
                maxBoxes-=1
                maxWeight-=boxes[r][1]
                if r==0 or boxes[r][0]!=boxes[r-1][0]:
                    trip+=1
                    last=r
                r+=1

            dp[r]=min(dp[r], dp[l]+trip+1)
            dp[last]=min(dp[last], dp[l]+trip)
            maxBoxes+=1
            maxWeight+=boxes[l][1]
            
            if l<n-1 and boxes[l][0]!=boxes[l+1][0]:
                trip-=1
        
        return dp[-1]

