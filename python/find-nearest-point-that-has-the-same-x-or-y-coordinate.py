class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        idx, dist=-1, float('inf')
        for i, p in enumerate(points):
            if p[0]==x or p[1]==y:
                d=abs(x-p[0])+abs(y-p[1])
                if d<dist:
                    idx=i
                    dist=d
        return idx

