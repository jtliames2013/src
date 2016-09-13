public class Solution {
    double powPositive(double x, long n) {
        if (n==0) return 1;
        double res=powPositive(x, n/2);
        res*=res;
        if (n%2==1) res*=x;
        return res;
    }
    
    public double myPow(double x, int n) {
        if (n>=0) {
            return powPositive(x, n);
        } else {
            return 1/powPositive(x, -((long)n));
        }
    }
}
