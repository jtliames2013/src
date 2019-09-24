1017. Convert to Base -2
Medium

92

112

Favorite

Share
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).

The returned string must have no leading zeroes, unless the string is "0".

 

Example 1:

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
Example 2:

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
Example 3:

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4
 

Note:

0 <= N <= 10^9

class Solution {
public:
    string baseNeg2(int N) {
        string res;
        while (N) {
            res.push_back((N&0x1)+'0');
            N=-(N>>1);
        }
        
        reverse(res.begin(), res.end());
        return res.empty()?"0":res;
    }
};
