198. House Robber  
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Hide Company Tags LinkedIn Airbnb
Hide Tags Dynamic Programming
Hide Similar Problems (M) Maximum Product Subarray (M) House Robber II (M) Paint House (E) Paint Fence (M) House Robber III

class Solution {
public:
    int rob(vector<int>& nums) {
        int odd=0, even=0;
        for (int i=0; i<nums.size(); i++) {
            if (i%2==0) {
                even=max(odd, even+nums[i]);
            } else {
                odd=max(even, odd+nums[i]);
            }
        }
        return max(odd, even);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1,0);
        dp[1]=nums[0];
        for (int i=2; i<=n; i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        
        return dp[n];
    }
};

3. get the list of houses
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<vector<int>> select(n+1);
        vector<int> dp(n+1, 0);
        dp[1]=nums[0];
        select[1].push_back({0});
        for (int i=2; i<=n; i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
            if (dp[i-1]<dp[i-2]+nums[i-1]) {
                select[i]=select[i-2];
                select[i].push_back(i-1);
            } else {
                select[i]=select[i-1];
            }
        }
        
        for (auto s:select[n]) cout << s << " ";
        cout << endl;
        return dp[n];
    }
};

