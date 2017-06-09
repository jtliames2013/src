43. Multiply Strings 
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
Hide Company Tags Facebook Twitter
Hide Tags Math String
Hide Similar Problems (M) Add Two Numbers (E) Plus One (E) Add Binary

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m=num1.size(), n=num2.size();
        vector<int> nums(m+n);
        
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                int val=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j, p2=i+j+1;
                val+=nums[p2];
                nums[p1]+=val/10;
                nums[p2]=val%10;
            }
        }
        
        for (int i=0; i<m+n-1; i++) {
            if (nums[i]!=0) {
                while (i<m+n-1) {
                    res+=nums[i]+'0';
                    i++;
                }
                break;
            }
        }
        res+=nums[m+n-1]+'0';
        return res;
    }
};

