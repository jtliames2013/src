# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        res, remain = [], []
        for i in intervals:
            if i.end<newInterval.start:
                res+=i,
            elif i.start>newInterval.end:
                remain+=i,
            else:
                newInterval.start=min(i.start, newInterval.start)
                newInterval.end=max(i.end, newInterval.end)
        res+=newInterval,
        res+=remain
        return res

