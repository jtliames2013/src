878. Nth Magical Number
Hard

141

45

Favorite

Share
A positive integer is magical if it is divisible by either A or B.

Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: N = 1, A = 2, B = 3
Output: 2
Example 2:

Input: N = 4, A = 2, B = 3
Output: 6
Example 3:

Input: N = 5, A = 2, B = 4
Output: 10
Example 4:

Input: N = 3, A = 6, B = 4
Output: 8
 

Note:

1 <= N <= 10^9
2 <= A <= 40000
2 <= B <= 40000

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long l=2, r=(long)N*min(A, B), mid;
        long lcm=A*B/gcd(A, B);
        while (l<r) {
            mid=l+(r-l)/2;
            if (mid/A+mid/B-mid/lcm<N) l=mid+1;
            else r=mid;
        }
        
        return r%mod;
    }
private:
    const int mod=1e9+7;
};

