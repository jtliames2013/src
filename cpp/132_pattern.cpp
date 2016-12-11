456. 132 Pattern   QuestionEditorial Solution  My Submissions
Total Accepted: 1360
Total Submissions: 5618
Difficulty: Medium
Contributors: love_FDU_llp
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
Subscribe to see which companies asked this question

Hide Tags Stack

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return false;
        int s3=INT_MIN;
        stack<int> stk;
        for (int i=n-1; i>=0; i--) {
            if (nums[i]<s3) return true;
            while (!stk.empty() && stk.top()<nums[i]) {
                s3=max(s3, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

