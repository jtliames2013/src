1256. Encode Number
Medium

17

61

Favorite

Share
Given a non-negative integer num, Return its encoding string.

The encoding is done by converting the integer to a string using a secret function that you should deduce from the following table:



 

Example 1:

Input: num = 23
Output: "1000"
Example 2:

Input: num = 107
Output: "101100"
 

Constraints:

0 <= num <= 10^9

Quora
|
LeetCode

"1"+f(n)=binary(n+1)

class Solution {
public:
    string encode(int num) {
        string res;
        int n=num+1;
        while (n>0) {
            res.push_back(((n&0x1)==0)?'0':'1');
            n>>=1;
        }
        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

