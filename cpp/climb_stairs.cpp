#include <stdio.h>
#include <vector>
#include <queue>

class Solution {
public:
    int climbStairs(int n) {
    	if (n <= 1) return 1;

    	int a = 1, b = 1, c;
    	for (int i = 2; i <= n; i++)
    	{
    		c = a + b;
    		a = b;
    		b = c;
    	}

    	return c;
    }
};

int main()
{
	return 0;
}

