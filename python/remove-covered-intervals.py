class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        res=len(intervals)
        intervals.sort(key=lambda i: (i[0], -i[1]))
        end=intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][1]<=end: res-=1
            else: end=intervals[i][1]
        return res

