class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        return [sum([(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=r1*r1 for x2, y2 in points]) for x1, y1, r1 in queries]

