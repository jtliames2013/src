300. Longest Increasing Subsequence 
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int len=1;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j]) {
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            len=max(len, dp[i]);
        }
        return len;
    }
};

2. 维护一个单调序列
遍历nums数组，二分查找每一个数在单调序列中的位置，然后替换之。
nums = [1, 5, 10, 3, 6, 7, 8]
sorted:
[1, 5, 10]
[1, 3, 10]
[1, 3, 6]
[1, 3, 6, 7]
...
https://en.wikipedia.org/wiki/Longest_increasing_subsequence    
http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> sorted;
        
        for (int i=0; i<n; i++) {
            auto iter = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (iter==sorted.end()) sorted.push_back(nums[i]);
            else *iter=nums[i];
        }
        return sorted.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> sorted;
        
        for (int i=0; i<n; i++) {
            int l=0, r=sorted.size()-1, mid;
            while (l<=r) {
                mid=l+(r-l)/2;
                if (sorted[mid]<nums[i]) l=mid+1;
                else r=mid-1;
            }
            if (l==sorted.size()) sorted.push_back(nums[i]);
            else sorted[l]=nums[i];
        }
        return sorted.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> sorted;

        for (int i=0; i<n; i++) {
            int l=0, r=sorted.size();
            while (l<r) {
                int mid=l+(r-l)/2;
                if (sorted[mid]<nums[i]) l=mid+1;
                else r=mid;
            }
            if (l==sorted.size()) sorted.push_back(nums[i]);
            else sorted[l]=nums[i];
        }
        
        return sorted.size();
    }
};
