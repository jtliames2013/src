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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int n=nums.size();
        if (n==0) return res;
        int l=0, r=n-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (nums[l]!=target) return res;
        else res[0]=l;
        
        r=n-1;
        while (l<r) {
            mid=l+(r-l)/2+1;
            if (nums[mid]>target) r=mid-1;
            else l=mid;
        }
        res[1]=r;
        
        return res;
    }
};

int main()
{
	return 0;
}


