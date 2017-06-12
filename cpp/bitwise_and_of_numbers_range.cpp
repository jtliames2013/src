201. Bitwise AND of Numbers Range
DescriptionHintsSubmissionsSolutions
Total Accepted: 54048
Total Submissions: 160447
Difficulty: Medium
Contributor: LeetCode
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Bit Manipulation

The idea is very simple:

1.last bit of (odd number & even number) is 0.
2.when m != n, There is at least an odd number and an even number, so the last bit position result is 0.
3.Move m and n rigth a position.
Keep doing step 1,2,3 until m equal to n, use a factor to record the iteration time.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int count=0;

    	while (m!=n) {
    		m>>=1;
    		n>>=1;
    		count++;
    	}

    	return n<<count;
    }
};

