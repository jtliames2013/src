class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        res, maxLen=0, 0
        for l, w in rectangles:
            mn=min(l, w)
            if mn>maxLen:
                maxLen=mn
                res=1
            elif mn==maxLen:
                res+=1
        
        return res

