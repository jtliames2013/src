class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        l=sorted((v[0], i) for i, v in enumerate(intervals))
        res=[]
        for i in intervals:
            pos=bisect.bisect_left(l, (i[1],))
            res.append(l[pos][1] if pos<len(l) else -1)
        return res
