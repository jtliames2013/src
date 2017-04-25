338. Counting Bits Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 72823
Total Submissions: 120579
Difficulty: Medium
Contributor: LeetCode
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num+1);
        if (num==0) return count;
        for (int i=1; i<=num; i++) {
            count[i]=count[i>>1]+(i&0x1);
        }
        
        return count;
    }
};

