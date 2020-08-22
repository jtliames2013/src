1556. Thousand Separator
Easy

20

4

Add to List

Share
Given an integer n, add a dot (".") as the thousands separator and return it in string format.

 

Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"
Example 3:

Input: n = 123456789
Output: "123.456.789"
Example 4:

Input: n = 0
Output: "0"
 

Constraints:

0 <= n < 2^31

class Solution {
public:
    string thousandSeparator(int n) {
        if (n==0) return "0";
        string res;
        for (int i=0; n>0; ++i, n/=10) {
            if (i>0 && i%3==0) res.push_back('.');
            res.push_back(n%10+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
