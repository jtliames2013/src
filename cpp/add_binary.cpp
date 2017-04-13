67. Add Binary  
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Hide Company Tags Facebook
Hide Tags Math String
Hide Similar Problems (M) Add Two Numbers (M) Multiply Strings (E) Plus One

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int m=a.size(), n=b.size();
        int i=m-1, j=n-1;
        bool carry=false;
        while (i>=0 || j>=0) {
            int num=0;
            if (i>=0) { 
                num+=a[i]-'0';
                i--;
            }
            if (j>=0) {
                num+=b[j]-'0';
                j--;
            }
            if (carry) {
                num++;
                carry=false;
            }
            if (num>1) {
                num%=2;
                carry=true;
            }
            res.push_back(num+'0');
        }
        
        if (carry) res.push_back('1');
        
        reverse(res.begin(), res.end());
        return res;
    }
};

