class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        mod=10**9+7
        buy, sell=[], []
        for price, amount, orderType in orders:
            if orderType==0:
                heappush(buy, [-price, amount])
            else:
                heappush(sell, [price, amount])
            while buy and sell and -buy[0][0]>=sell[0][0]:
                mn=min(buy[0][1], sell[0][1])
                buy[0][1]-=mn
                sell[0][1]-=mn
                if buy[0][1]==0: heappop(buy)
                if sell[0][1]==0: heappop(sell)
        return sum(a for p, a in buy+sell)%mod

