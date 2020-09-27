class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        profit, waiting, maxProfit, rotation, res, i=0, 0, float('-inf'), 0, 0, 0
        while waiting>0 or i<len(customers):
            if i<len(customers):               
                waiting+=customers[i]
                i+=1
                
            if waiting>=4:
                profit+=4*boardingCost
                waiting-=4
            else:
                profit+=waiting*boardingCost
                waiting=0
            profit-=runningCost
            rotation+=1
            
            if profit>maxProfit:
                maxProfit=profit
                res=rotation
                        
        return res if profit>0 else -1

