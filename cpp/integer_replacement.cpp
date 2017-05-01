397. Integer Replacement Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 17728
Total Submissions: 59800
Difficulty: Medium
Contributor: LeetCode
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1

Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
Subscribe to see which companies asked this question.

Hide Tags Math Bit Manipulation

if a number ends with 01, then certainly decrementing is the way to go. Otherwise, if it ends with 11, then certainly incrementing is at least as good as decrementing 

class Solution {
public:
    int integerReplacement(int n) {
        int count=0;
        long long num=n;
        while (num>1) {
            if ((num & 0x1)==0) {
                num>>=1;
            } else if (num==3 || ((num>>1) & 0x1)==0) {
                num--;
            } else {
                num++;
            }
            count++;
        }
        return count;
    }
};

2. Recursion
class Solution {
public:
    int dfs(long long num) {
        if (num==1) return 0;
        if (num==3) return 2;
        if (num%2==0) return dfs(num/2)+1;
        else {
            if ((num+1)%4==0) return dfs(num+1)+1;
            else return dfs(num-1)+1;
        }
    }
    
    int integerReplacement(int n) {
        return dfs(n);
    }
};
