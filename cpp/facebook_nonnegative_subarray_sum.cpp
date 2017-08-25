12.  在一个nonnegative array里找continuous sequence 加起来等于特定值的一道题

class Solution {
public:
    int SubArraySum(int s, vector<int>& nums) {
        int n=nums.size(), l=0, r=0;
        int sum=0;
        int res=INT_MAX;
        for (; r<n; r++) {
            sum+=nums[r];
            while (sum>s) {
                sum-=nums[l];
                l++;
            }
            if (sum==s) return true;
        }
        
        return false;
    }
};
