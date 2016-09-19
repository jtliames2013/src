public class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit=0;
        for (int i=1; i<prices.length; i++) {
            int diff=prices[i]-prices[i-1];
            if (diff>0) maxprofit+=diff;
        }
        return maxprofit;
    }
}
