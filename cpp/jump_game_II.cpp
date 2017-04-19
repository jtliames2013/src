45. Jump Game II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 88426
Total Submissions: 339133
Difficulty: Hard
Contributor: LeetCode
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

Subscribe to see which companies asked this question.

Hide Tags Array Greedy

依旧贪心去推，贪心的规则就是在能够到达的范围之内，选择一个能够到达最远距离的点，更新步数，和更新最远到达的范围。

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0, reach=0;
        int n=nums.size();
        for (int i=0; i<n;) {
            if (reach>=n-1) break;
            int maxReach=INT_MIN;
            for (int j=i; j<=reach; j++) {
                maxReach=max(maxReach, j+nums[j]);
            }
            i=reach+1;
            reach=maxReach;
            steps++;
        }
        
        return steps;
    }
};

