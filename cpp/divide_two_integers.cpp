29. Divide Two Integers  
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0) {
            if (dividend==0) return INT_MIN;
            else return INT_MAX;
        }
        if (dividend==INT_MIN&&divisor==-1) return INT_MAX;
        int res=0;
        bool neg=(dividend>0&&divisor<0) || (dividend<0&&divisor>0);
        unsigned long long dd=abs((long long) dividend);
        unsigned long long dr=abs((long long) divisor);
        while (dd>=dr) {
            int i=0;
            while (dd>=(dr<<i)) i++;
            
            res+=1<<(i-1);
            dd-=(dr<<(i-1));
        }
        
        if (neg) res=-res;
        return res;
    }
};

int main()
{
	return 0;
}


