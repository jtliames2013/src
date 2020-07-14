class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        left, bottom, right, top=float('inf'), float('inf'), float('-inf'), float('-inf')
        minDist, minX, minY=float('inf'), 0, 0
        for p in positions:
            left=min(left, p[0])
            right=max(right, p[0])
            bottom=min(bottom, p[1])
            top=max(top, p[1])
        
        delta=10
        while delta>=0.0001:
            x=left
            while x<=right:
                y=bottom
                while y<=top:
                    dist=0
                    for p in positions:
                        dist+=sqrt((x-p[0])*(x-p[0])+(y-p[1])*(y-p[1]))
                    if dist<minDist:
                        minDist=dist
                        minX=x
                        minY=y
                    
                    y+=delta
                x+=delta            

            left=minX-delta
            right=minX+delta
            bottom=minY-delta
            top=minY+delta
                
            delta/=10
        return minDist

