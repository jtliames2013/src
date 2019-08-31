168. Excel Sheet Column Title 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n>0) {
            int num=n%26;
            if (num==0) {
                // borrow from high digit
                n-=26;
                num=26;
            }
            res.push_back('A'+num-1);
            n/=26;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

