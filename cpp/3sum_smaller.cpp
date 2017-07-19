259. 3Sum Smaller
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]

Follow up:
Could you solve it in O(n2) runtime? 

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res=0;
        int n=nums.size();
        if (n<3) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            if (nums[i]+nums[l]+nums[l+1]>=target) break;
            if (nums[i]+nums[r]+nums[r-1]<target) {
                res+=(r-l+1)*(r-l)/2;
                continue;
            }
            
            while (l<r) {
                if (nums[i]+nums[l]+nums[r]<target) {
                    res+=r-l;
                    l++;
                } else {
                    r--;
                }            
            }
        }
        
        return res;
    }
};

