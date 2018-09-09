866. Prime Palindrome
DescriptionHintsSubmissionsDiscussSolution
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101
 

Note:

1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.

All palindrome with even digits is multiple of 11.

We can prove as follow:

11 % 11 = 0
1111 % 11 = 0
111111 % 11 = 0
11111111 % 11 = 0

So:
1001 % 11 = (1111 - 11 * 10) % 11 = 0
100001 % 11 = (111111 - 1111 * 10) % 11 = 0
10000001 % 11 = (11111111 - 111111 * 10) % 11 = 0

For any palindrome with even digits:
abcddcba % 11
= (a * 10000001 + b * 100001 * 10 + c * 1001 * 100 + d * 11 * 1000) % 11
= 0

All palindrome with even digits is multiple of 11.
So among them, 11 is the only one prime
if (8 <= N <= 11) return 11
For other, we consider only palindrome with odd dights.

class Solution {
public:
    bool isPrime(int N) {
        if (N<2) return false;
        for (int i=2; i*i<=N; ++i) {
            if (N%i==0) return false;
        }
        return true;
    }
    
    int primePalindrome(int N) {
        if (N>=8 && N<=11) return 11;
        for (int i=1; i<100000; ++i) {
            string s=to_string(i), r(s.rbegin(), s.rend());
            int n=stoi(s+r.substr(1));
            if (n>=N && isPrime(n)) return n;
        }
        return -1;
    }
};

