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
        int n1=num1.size(), n2=num2.size();
        int i=n1-1, j=n2-1;
        bool carry=false;
        int num;
        while (i>=0 || j>=0) {
            num=0;
            if (i>=0 && j>=0) {
                num=num1[i]-'0'+num2[j]-'0';
                i--;
                j--;
            } else if (i>=0) {
                num=num1[i]-'0';
                i--;
            } else {
                num=num2[j]-'0';
                j--;
            }
            if (carry) {
                num++;
                carry=false;
            }
            if (num>9) {
                num%=10;
                carry=true;
            }
            res.push_back(num+'0');
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
