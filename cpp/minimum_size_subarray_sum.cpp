209. Minimum Size Subarray Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 45383 Total Submissions: 164718 Difficulty: Medium
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

这道题给定了我们一个数字，让我们求子数组之和大于等于给定值的最小长度，跟之前那道 Maximum Subarray 最大子数组有些类似，并且题目中要求我们实现O(n)和O(nlgn)两种解法，那么我们先来看O(n)的解法，我们需要定义两个指针left和right，分别记录子数组的左右的边界位置，然后我们让right向右移，直到子数组和大于等于给定值或者right达到数组末尾，此时我们更新最短距离，并且将left像右移一位，然后再sum中减去移去的值，然后重复上面的步骤，直到right到达末尾，且left到达临界位置，即要么到达边界，要么再往右移动，和就会小于给定值。代码如下：

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
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int minlen=INT_MAX;
        int sum=0;
        int l, r;
        for (l=0, r=0; r<n; r++) {
            sum+=nums[r];
            
            while (sum>=s) {
                minlen=min(minlen, r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        
        if (minlen==INT_MAX) return 0;
        else return minlen;
    }
};

2.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int minlen=INT_MAX;
        int sum=0;
        for (int l=0, r=0; r<n; r++) {
            sum+=nums[r];
            if (sum>=s) {
                while (sum>=s) {
                    sum-=nums[l];
                    l++;
                }
                minlen=min(minlen, r-l+2);
            }
        }
        if (minlen==INT_MAX) return 0;
        else return minlen;
    }
};

int main()
{
	return 0;
}


