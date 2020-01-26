1330. Reverse Subarray To Maximize Array Value
Hard

35

4

Add to List

Share
You are given an integer array nums. The value of this array is defined as the sum of |nums[i]-nums[i+1]| for all 0 <= i < nums.length-1.

You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.

Find maximum possible value of the final array.

 

Example 1:

Input: nums = [2,3,1,5,4]
Output: 10
Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
Example 2:

Input: nums = [2,4,9,24,2,1,10]
Output: 68
 

Constraints:

1 <= nums.length <= 3*10^4
-10^5 <= nums[i] <= 10^5

What's the score after reversing a sub-array [L, R] ?

It's the score without reversing it + abs(a[R] - a[L-1]) + abs(a[L] - a[R+1]) - abs(a[L] - a[L-1]) - abs(a[R] - a[R+1])

How to maximize that formula given that abs(x - y) = max(x - y, y - x) ?

This can be written as max(max(a[R] - a[L - 1], a[L - 1] - a[R]) + max(a[R + 1] - a[L], a[L] - a[R + 1]) - value(L) - value(R + 1)) over all 
L < R where value(i) = abs(a[i] - a[i-1])

Assume the list is : x, y, ..., a, [b, ..., c], d, ..., and we are going to reverse [b, ..., c].
The amount of total value change is -[abs(a-b)+abs(c-d)] + [abs(a-c)+abs(b-d)]
The goal is to maximize (min(a,b) - max(c, d)) when not overlap
    |            |
  min(c,d)   max(c,d)
	                  |                   |
                      min(a,b)           max(a,b)

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n=nums.size(), res=0, onediff=0, mn=INT_MAX, mx=INT_MIN;        
        for (int i=0; i<n-1; ++i) {
            int a=nums[i], b=nums[i+1];
            res+=abs(a-b);
            onediff=max(onediff, abs(nums[0]-b)-abs(a-b));
            onediff=max(onediff, abs(nums[n-1]-a)-abs(a-b));
            mn=min(mn, max(a, b));
            mx=max(mx, min(a, b));
            
        }
        return res+max(onediff, (mx-mn)*2);
    }
};

