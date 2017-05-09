537. Complex Number Multiplication Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5784
Total Submissions: 8822
Difficulty: Medium
Contributors:
love_Fawn
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
Subscribe to see which companies asked this question.

Hide Tags Math String

class Solution {
public:
    pair<int,int> parse(string& s) {
        int a, b;
        char op, i;
        istringstream iss(s);
        iss >> a >> op >> b >> i;
        
        return {a,b};
    }
    
    string complexNumberMultiply(string a, string b) {
        pair<int,int> n1=parse(a);
        pair<int,int> n2=parse(b);
        return to_string(n1.first*n2.first-n1.second*n2.second) + "+" + to_string(n1.first*n2.second+n1.second*n2.first) + "i";
    }
};

