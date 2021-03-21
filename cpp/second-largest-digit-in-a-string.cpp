1796. Second Largest Digit in a String
Easy

19

19

Add to List

Share
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.

 

Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit. 
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.

class Solution {
public:
    int secondHighest(string s) {
        int mx1=-1, mx2=-1;
        for (auto& c:s) {
            if (!isdigit(c)) continue;
            int num=c-'0';
            if (num>mx1) {
                mx2=mx1;
                mx1=num;
            } else if (num<mx1 && num>mx2) {
                mx2=num;
            }
        }
        return mx2;
    }
};

