class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        n=len(customers)
        waitTime, serveTime=0, 0
        for arrival, time in customers:
            waitTime+=max(0, serveTime-arrival)+time
            serveTime=max(serveTime, arrival)+time
        
        return waitTime/n

