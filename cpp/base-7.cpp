504. Base 7 Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 12346
Total Submissions: 27120
Difficulty: Easy
Contributors:
satyapriya
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].

class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        bool neg=num<0;
        if (neg) num=-num;
        string res;
        while (num>0) {
            res+=num%7+'0';
            num/=7;
        }
        
        reverse(res.begin(), res.end());
        if (neg) res="-"+res;
        return res;
    }
};
