public class Solution {
    public int arrangeCoins(int n) {
        long l=0, r=n;
        long mid;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (mid*(mid+1)/2<=n) l=mid;
            else r=mid-1;
        }
        return (int)l;
    }
}

