171. Excel Sheet Column Number 
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for (auto c:s) {
            res*=26;
            res+=c-'A'+1;
        }
        return res;
    }
};
