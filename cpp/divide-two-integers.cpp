29. Divide Two Integers  
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0) {
            if (dividend==0) return INT_MAX;
            else return INT_MAX;
        }
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        long res=0;
        bool neg=(dividend<0 ^ divisor<0);
        long dd=abs((long)dividend);
        long dr=abs((long)divisor);
        
        while (dd>=dr) {
            int i=0;
            while (dd>=(dr<<i)) i++;
            i--;
            res+=1<<i;
            dd-=(dr<<i);
        }
        return neg?-res:res;
    }
};
