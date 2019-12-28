625. Minimum Factorization
DescriptionHintsSubmissionsSolutions
Total Accepted: 1510
Total Submissions: 5497
Difficulty: Medium
Contributors:
gld
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 
Output:
68
Example 2
Input:

15
Output:
35
Subscribe to see which companies asked this question.

Hide Tags Recursion Math

http://www.geeksforgeeks.org/find-smallest-number-whose-digits-multiply-given-number-n/
For a given n, following are the two cases to be considered.
Case 1: n < 10 When n is smaller than n, the output is always n+10. For example for n = 7, output is 17. For n = 9, output is 19.

Case 2: n >= 10 Find all factors of n which are between 2 and 9 (both inclusive). The idea is to start searching from 9 so that the number of digits in result are minimized. For example 9 is preferred over 33 and 8 is preferred over 24.
Store all found factors in an array. The array would contain digits in non-increasing order, so finally print the array in reverse order.

Tencent
|
LeetCode

class Solution {
public:
    int smallestFactorization(int a) {
        if (a<2) return a;
        long res=0;
        for (int i=9, d=0; i>=2 && d<10; i--) {
            while (a%i==0 && d<10) {
                res+=i*pow(10, d++);
                a/=i;
            }
        }
        
        return (a>1 || res>INT_MAX)?0:res;
    }
};

