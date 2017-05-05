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

We want to search for a subsequence (s1,s2,s3)

INTUITION: The problem would be simpler if we want to find sequence with s1 > s2 > s3, we just need to find s1, followed by s2 and s3. Now if we want to find a 132 sequence, we need to switch up the order of searching. we want to first find s2, followed by s3, then s1.

IDEA: We can start from either side but I think starting from the end allow us to finish in a single pass. The idea is to start from end and search for a candidate for s2 and s3. A number becomes a candidate for s3 if there is any number on the left of s2 that is bigger than it.

DETECTION: Keep track of the largest candidate of s3 and once we encounter any number smaller than s3, we know we found a valid sequence since s1 < s3 implies s1 < s2.

IMPLEMENTATION:

Have a stack, each time we store a new number, we first pop out all numbers that are smaller than that number. The numbers that are popped out becomes candidate for s3.
We keep track of the maximum of such s3 (which is always the most recently popped number from the stack).
Once we encounter any number smaller than s3, we know we found a valid sequence since s1 < s3 implies s1 < s2.
RUNTIME: Each item is pushed and popped once at most, the time complexity is therefore O(n).

EXAMPLE:
i = 6, nums = [ 9, 11, 8, 9, 10, 7, 9 ], S1 candidate = 9, S3 candidate = None, Stack = Empty
i = 5, nums = [ 9, 11, 8, 9, 10, 7, 9 ], S1 candidate = 7, S3 candidate = None, Stack = [9]
i = 4, nums = [ 9, 11, 8, 9, 10, 7, 9 ], S1 candidate = 10, S3 candidate = None, Stack = [9,7]
i = 3, nums = [ 9, 11, 8, 9, 10, 7, 9 ], S1 candidate = 9, S3 candidate = 9, Stack = [10]
i = 2, nums = [ 9, 11, 8, 9, 10, 7, 9 ], S1 candidate = 8, S3 candidate = 9, Stack = [10,9] We have 8<9, sequence found!

EDIT: Thanks @Pumpkin78 and @dalwise for pointing out that the maximum candidate for s3 is always the recently popped number from the stack, because if we encounter any entry smaller than the current candidate, the function would already have returned.

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int s3=INT_MIN;
        for (int i=nums.size()-1; i>=0; i--) {
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

