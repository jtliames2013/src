public class Solution {
    public boolean isPerfectSquare(int num) {
        long l=0, r=num;
        long mid;
        while (l<=r) {
            mid=l+(r-l)/2;
            long prod=mid*mid;
            if (prod==num) return true;
            else if (prod<num) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
}
