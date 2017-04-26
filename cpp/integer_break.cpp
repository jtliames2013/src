343. Integer Break Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 39590
Total Submissions: 87117
Difficulty: Medium
Contributor: LeetCode
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Mat

For any integer p strictly greater than 4, it has the property such that 3 * (p - 3) > p, which means breaking it into two integers 3 and p - 3 makes the product larger while keeping the sum unchanged. If p - 3 is still greater than 4, we should break it again into 3 and p - 6, giving 3 * 3 * (p - 6), and so on, until we cannot break it (less than or equal to 4) anymore.

For integer 4, breaking it into 2 * 2 or keeping it as 4 does not change its contribution to the product.
We cannot have more than two 4s, because 2 * 3 * 3 > 4 * 4. We cannot have more than three 2s because 3 * 3 > 2 * 2 * 2.

class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        int product=1;
        while (n>4) {
            product*=3;
            n-=3;
        }
        product*=n;
        
        return product;
    }
};

