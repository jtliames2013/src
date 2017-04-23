326. Power of Three Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 89300
Total Submissions: 224407
Difficulty: Easy
Contributor: LeetCode
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Math
Hide Similar Problems (E) Power of Two (E) Power of Four

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        
        while (n>1) {
            if (n%3!=0) return false;
            n/=3;
        }
        return true;
    }
};
