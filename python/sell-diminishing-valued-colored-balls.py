class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        mod=10**9+7
        res, i, width=0, 0, 0
        l=sorted(collections.Counter(inventory).items(), reverse=True)+[(0, 0)]
        while orders>0:
            width+=l[i][1]
            height=l[i][0]-l[i+1][0]
            total=min(orders, width*height)
            div=total//width
            rem=total%width
            high, low=l[i][0], l[i][0]-div
            res+=width*((high+1)*high//2 - (low+1)*low//2) + rem*low
            orders-=total
            i+=1
            
        return res%mod

