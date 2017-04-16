461. Hamming Distance Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 52004
Total Submissions: 73603
Difficulty: Easy
Contributors:
Samuri
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
Subscribe to see which companies asked this question.

Hide Tags Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits (M) Total Hamming Distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int val=x^y;
        int sum=0;
        while (val>0) {
            val &= val-1;
            sum++;
        }
        return sum;
    }
};
