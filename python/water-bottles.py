class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res, empty=0, 0
        while numBottles>0:
            res+=numBottles
            total=numBottles+empty
            numBottles=total//numExchange
            empty=total%numExchange
        return res
