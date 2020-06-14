class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stk=[]
        for i, v in enumerate(prices):
            while stk and prices[stk[-1]]>=v:
                prices[stk[-1]]-=v
                stk.pop()
            stk.append(i)
        return prices

