415. Add Strings   QuestionEditorial Solution  My Submissions
Total Accepted: 8710 Total Submissions: 20969 Difficulty: Easy Contributors: Admin
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
Subscribe to see which companies asked this question

Hide Tags Math
Hide Similar Problems (M) Add Two Numbers (M) Multiply Strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i1=num1.size()-1, i2=num2.size()-1, num=0;
        while (i1>=0 || i2>=0) {
            if (i1>=0) num+=num1[i1--]-'0';
            if (i2>=0) num+=num2[i2--]-'0';
            res.push_back(num%10+'0');
            num/=10;
        }

        if (num>0) res.push_back(num+'0');

        reverse(res.begin(), res.end());
        return res;
    }
};
