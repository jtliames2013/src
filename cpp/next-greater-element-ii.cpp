503. Next Greater Element II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 9567
Total Submissions: 20199
Difficulty: Medium
Contributors:
love_Fawn
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.

Subscribe to see which companies asked this question.

Hide Tags Stack
Hide Similar Problems (E) Next Greater Element I (M) Next Greater Element III

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return vector<int>();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i=0; i<2*n; i++) {
            int index=i%n;
            while (!stk.empty() && nums[stk.top()]<nums[index]) {
                res[stk.top()]=nums[index];
                stk.pop();
            }
            stk.push(index);
        }
        
        return res;
    }
};

