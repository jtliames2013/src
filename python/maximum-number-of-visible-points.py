class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        d, res, same=[], 0, 0
        for p in points:
            if p[0]==location[0] and p[1]==location[1]: same+=1
            else:
                d.append(atan2((p[1]-location[1]), (p[0]-location[0])))
        d.sort()
        d=d+[i+2*pi for i in d]
        angle*=pi/180
        i=0
        for j in range(len(d)):
            while d[j]-d[i]>angle: i+=1
            res=max(res, j-i+1)
        return res+same

