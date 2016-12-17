169. Majority Element  
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Adobe Zenefits
Hide Tags Array Divide and Conquer Bit Manipulation
Hide Similar Problems (M) Majority Element II

Boyer–Moore majority vote algorithm
https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

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
#include <math.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	//MJRTY-A Fast Majority Vote Algorithm
    	int candidate=0, cnt=0;

    	for (int i=0; i<nums.size(); i++) {
    		if (cnt==0) {
    			candidate=nums[i];
    			cnt++;
    		} else if (candidate==nums[i]) {
    			cnt++;
    		} else {
    			cnt--;
    		}
    	}

    	return candidate;
    }
};

int main()
{
	return 0;
}

