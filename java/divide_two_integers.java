public class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor==0) {
            if (dividend>0) return Integer.MAX_VALUE;
            else return Integer.MIN_VALUE;
        }
        
        if (dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
        int res=0;
        boolean neg=(dividend>0&&divisor<0)||(dividend<0&&divisor>0);
        long dd=Math.abs((long)dividend);
        long dr=Math.abs((long)divisor);
        
        while (dd>=dr) {
            int i=0;
            while ((dr<<i+1)<dd) {
                i++;
            }
            res+=1<<i;
            dd-=(dr<<i);
        }
        
        if (neg) res=-res;
        return res;
    }
}
