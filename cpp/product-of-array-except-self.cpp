238. Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Hide Company Tags Amazon LinkedIn Apple Facebook Microsoft
Hide Tags Array
Hide Similar Problems (H) Trapping Rain Water (M) Maximum Product Subarray (H) Paint House II

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, 1);
        int prod=1;
        for (int i=1; i<n; i++) {
            res[i]=res[i-1]*nums[i-1];
        }
        
        for (int i=n-2; i>=0; i--) {
            prod*=nums[i+1];
            res[i]=res[i]*prod;
        }
        
        return res;
    }
};

