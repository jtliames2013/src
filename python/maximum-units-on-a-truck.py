class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        res=0
        boxTypes.sort(key=lambda x: -x[1])
        for box, units in boxTypes:
            if truckSize==0: break
            mn=min(box, truckSize)
            res+=mn*units
            truckSize-=mn
        return res

