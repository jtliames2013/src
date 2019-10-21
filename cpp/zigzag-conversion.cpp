6. ZigZag Conversion
Medium

1229

3711

Favorite

Share
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows==1) return s;
        vector<string> rows(numRows);
        int index=0, step=1;
        for (auto c:s) {
            rows[index]+=c;
            if (index==0) step=1;
            else if (index==numRows-1) step=-1;
            index+=step;
        }
        for (auto& r:rows) res+=r;
        return res;
    }
};
