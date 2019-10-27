1191. K-Concatenation Maximum Sum
Medium

144

18

Favorite

Share
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size(), global=INT_MIN, local=0;
        long total=accumulate(arr.begin(), arr.end(), 0);
        for (int i=0; i<n*min(k, 2); ++i) {
            local=max(arr[i%n], arr[i%n]+local);
            global=max(global, local);
        }
        return max<long>({0, global, total*max(0, k-2)+global})%mod;
    }
private:
    const int mod=1e9+7;
};
