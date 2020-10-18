class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        res, maxQuality=[0, 0], 0
        for i in range(51):
            for j in range(51):
                total=0
                for x, y, q in towers:
                    d=dist([x, y], [i, j])
                    if d<=radius: total+=q//(1+d)
                if total>maxQuality:
                    maxQuality=total
                    res=[i, j]
        return res

