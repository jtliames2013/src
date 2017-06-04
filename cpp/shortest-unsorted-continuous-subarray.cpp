581. Shortest Unsorted Continuous Subarray
DescriptionHintsSubmissionsSolutions
Total Accepted: 5667
Total Submissions: 19337
Difficulty: Easy
Contributors:
love_Fawn
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
Subscribe to see which companies asked this question.

Hide Tags Array

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        int start=n-1, minVal=nums[n-1], end=0, maxVal=nums[0];
        // find the left most one increasing
        for (int i=n-2; i>=0; i--) {
            minVal=min(minVal, nums[i]);
            if (nums[i]>minVal) start=i;
        }
        // find the right most one decreasing
        for (int i=1; i<n; i++) {
            maxVal=max(maxVal, nums[i]);
            if (nums[i]<maxVal) end=i;
        }
        
        return start>=end?0:end-start+1;
    }
};

