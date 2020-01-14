1318. Minimum Flips to Make a OR b Equal to c
Medium

34

5

Add to List

Share
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0
 

Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        for (int i=0; i<32; ++i) {
            int at=a&1, bt=b&1, ct=c&1;
            if (ct==0) {
                res+=at+bt;
            } else {
                res+=(at==0 && bt==0)?1:0;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return res;
    }
};

