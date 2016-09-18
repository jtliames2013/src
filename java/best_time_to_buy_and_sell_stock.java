public class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit=0;
        if (prices.length<=1) return 0;
        int maxprice=prices[prices.length-1];
        for (int i=prices.length-2; i>=0; i--) {
            maxprofit=Math.max(maxprofit, maxprice-prices[i]);
            maxprice=Math.max(maxprice, prices[i]);
        }
        
        return maxprofit;
    }
}
