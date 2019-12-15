1287. Element Appearing More Than 25% In Sorted Array
Easy

22

2

Favorite

Share
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5

Google
|
LeetCode

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        for (int i=1; i<=3; ++i) {
            int val=arr[n/4*i];
            auto lower=lower_bound(arr.begin(), arr.end(), val);
            auto upper=upper_bound(arr.begin(), arr.end(), val);
            if (distance(lower, upper)>n/4) return val;
        }
        return 0;
    }
};

