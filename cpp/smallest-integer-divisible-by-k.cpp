1015. Smallest Integer Divisible by K
Medium

63

193

Favorite

Share
Given a positive integer K, you need find the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.

Return the length of N.  If there is no such N, return -1.

 

Example 1:

Input: 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.
Example 2:

Input: 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.
Example 3:

Input: 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3.
 

Note:

1 <= K <= 10^5

If any remainder is 0, then the current number is the smallest integer divisible by K.
If none of the remainders is 0, then at some point, there must be some duplicate remainders (due to Pigeonhole principle), as the K remainders can only take at most K-1 different values excluding 0. In this case, no number with the pattern 1...1 is divisible by K. This is because once a remainder has a duplicate, the next remainder will be in a loop, as the previous remainder determines the next_mod, i.e., next_mod = (10 * prev_mod + 1) % K. Therefore, we will never see remainder==0

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K%2==0 || K%5==0) return -1;
        for (int i=0, len=1; len<=K; ++len) {
            i=(i*10+1)%K;
            if (i==0) return len;
        }
        return -1;
    }
};
