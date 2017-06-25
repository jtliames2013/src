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
        int n=nums.size();
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        int res=0;
        for (int i=0; i<n-2; i++) {
            if (nums[i]+nums[i+1]+nums[i+2]>=target) break;
            int l=i+1, r=n-1;
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

