class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        res=0
        if not intervals: return res
        intervals.sort(key=lambda i: i[1])
        end=intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0]<end: res+=1
            else: end=intervals[i][1]
        return res

