1363. Largest Multiple of Three
Hard

8

9

Add to List

Share
Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

 

Example 1:

Input: digits = [8,1,9]
Output: "981"
Example 2:

Input: digits = [8,6,7,1,0]
Output: "8760"
Example 3:

Input: digits = [1]
Output: ""
Example 4:

Input: digits = [0,0,0,0,0,0]
Output: "0"
 

Constraints:

1 <= digits.length <= 10^4
0 <= digits[i] <= 9
The returning answer must not contain unnecessary leading zeros.

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string res;
        int n=digits.size(), sum=0;
        bool one=false, two=false;
        for (int i=0; i<n; ++i) {
            sum+=digits[i];
            if (digits[i]%3==1) one=true;
            else if (digits[i]%3==2) two=true;
        }
        sort(digits.begin(), digits.end());

        if (sum%3==1) {
            if (one) {
                remove(digits, 1, 1);
            } else {
                remove(digits, 2, 2);
            }
        } else if (sum%3==2) {
            if (two) {
                remove(digits, 1, 2);
            } else {
                remove(digits, 2, 1);
            }
        }

        for (auto iter=digits.rbegin(); iter!=digits.rend(); ++iter) res+=*iter+'0';
        if (res.size()>1 && res[0]=='0') return "0";
        return res;
    }
private:
    void remove(vector<int>& digits, int count, int rem) {
        for (auto iter=digits.begin(); iter!=digits.end(); ) {
            if (*iter%3==rem) {
                count--;
                iter=digits.erase(iter);
                if (count==0) break;
            } else {
                iter++;
            }
        }
    }
};

