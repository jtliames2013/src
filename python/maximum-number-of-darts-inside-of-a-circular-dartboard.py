class Solution:
    def numPoints(self, points: List[List[int]], r: int) -> int:
        res=1
        for (x1, y1), (x2, y2) in itertools.combinations(points, 2):
            d=sqrt((x2-x1)**2+(y2-y1)**2)
            if d>2*r: continue
            l=sqrt(r*r-(d/2)*(d/2))
            c1=(x1+x2)/2-l*(y2-y1)/d
            c2=(y1+y2)/2+l*(x2-x1)/d
            res=max(res, sum((x-c1)**2+(y-c2)**2<=r*r+1e-6 for x, y in points))
        return res
