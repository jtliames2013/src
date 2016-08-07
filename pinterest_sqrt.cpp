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
    int mySqrt(int x) {
    	if (x<0) return -1;
    	if (x==0) return 0;
    	if (x==1) return 1;

    	int start=0, end=x;
    	int mid;
    	while (start<=end) {
    		mid=(start+end)/2;
    		if (x/mid==mid) return mid;
    		else if (x/mid>mid) start=mid+1;
    		else end=mid-1;
    	}

    	return end;
    }
};

class Solution {
public:
	float mysqrt(float num) {
		float l=0, r=num;
		float mid=(l+r)/2;

		while (abs(mid*mid-num)>0.001) {
			if (mid*mid>num) r=mid;
			else if (mid*mid<num) l=mid;
			mid=(l+r)/2;
		}

		return mid;
	}
};

int main()
{
	return 0;
}


