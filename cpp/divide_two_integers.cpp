29. Divide Two Integers  
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0) {
            if (dividend==0) return INT_MIN;
            else return INT_MAX;
        }
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        int res=0;
        bool neg=(dividend>0&&divisor<0) || (dividend<0&&divisor>0);
        unsigned long long dd=abs((long long)dividend);
        unsigned long long dr=abs((long long)divisor);
        
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

