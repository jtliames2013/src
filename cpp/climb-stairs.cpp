70. Climbing Stairs Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 164681
Total Submissions: 419426
Difficulty: Easy
Contributor: LeetCode
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        int a=1, b=1, c;
        for (int i=2; i<=n; i++) {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};

