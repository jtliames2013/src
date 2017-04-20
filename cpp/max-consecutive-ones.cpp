485. Max Consecutive Ones Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 33430
Total Submissions: 61429
Difficulty: Easy
Contributors:
Stomach_ache
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Subscribe to see which companies asked this question.

Hide Tags Array
Hide Similar Problems (M) Max Consecutive Ones II

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, n=nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i]==1) {
                int j=i+1;
                while (j<n && nums[j]==1) j++;
                count=max(count, j-i);
                i=j;
            }
        }
        
        return count;
    }
};

