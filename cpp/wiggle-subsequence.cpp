376. Wiggle Subsequence   QuestionEditorial Solution  My Submissions
Total Accepted: 12545 Total Submissions: 36521 Difficulty: Medium Contributors: Admin
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Greedy

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if (n<=1) return n;
        int up=1, down=1;
        for (int i=1; i<n; i++) {
            if (nums[i]>nums[i-1]) {
                up=down+1;
            } else if (nums[i]<nums[i-1]) {
                down=up+1;
            }
        }
        return max(up, down);
    }
};

2. DP array
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> up(n,1), down(n,1);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j]) {
                    up[i]=max(up[i], down[j]+1);
                } else if (nums[i]<nums[j]) {
                    down[i]=max(down[i], up[j]+1);
                }
            }
        }
        return max(up[n-1], down[n-1]);
    }
};
