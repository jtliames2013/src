1134. Armstrong Number
Easy

27

5

Favorite

Share
The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.

Given a positive integer N, return true if and only if it is an Armstrong number.

 

Example 1:

Input: 153
Output: true
Explanation: 
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
Example 2:

Input: 123
Output: false
Explanation: 
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
 

Note:

1 <= N <= 10^8

0 ~ 6 months6 months ~ 1 year1 year ~ 2 years

Amazon
|
LeetCode

class Solution {
public:
    bool isArmstrong(int N) {
        int k=0, x=N, sum=0;
        while (x>0) {
            k++;
            x/=10;
        }
        x=N;
        while (x>0) {
            sum+=pow(x%10, k);
            x/=10;
        }
        return sum==N;
    }
};

