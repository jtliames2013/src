1271. Hexspeak
Easy

15

23

Favorite

Share
A decimal number can be converted to its Hexspeak representation by first converting it to an uppercase hexadecimal string, then replacing all occurrences of the digit 0 with the letter O, and the digit 1 with the letter I.  Such a representation is valid if and only if it consists only of the letters in the set {"A", "B", "C", "D", "E", "F", "I", "O"}.

Given a string num representing a decimal integer N, return the Hexspeak representation of N if it is valid, otherwise return "ERROR".

 

Example 1:

Input: num = "257"
Output: "IOI"
Explanation:  257 is 101 in hexadecimal.
Example 2:

Input: num = "3"
Output: "ERROR"
 

Constraints:

1 <= N <= 10^12
There are no leading zeros in the given string.
All answers must be in uppercase letters.

Virtu Financial
|
LeetCode

1.
class Solution {
public:
    string toHexspeak(string num) {
        long n=stol(num);
        stringstream ss;
        ss << hex << uppercase << n;
        string res(ss.str());
        for (int i=0; i<res.size(); ++i) {
            if (res[i]>'1' && res[i]<='9') return "ERROR";
            else if (res[i]=='0') res[i]='O';
            else if (res[i]=='1') res[i]='I';
        }
        return res;
    }
};

2.
class Solution {
public:
    string toHexspeak(string num) {
        long n=stol(num);
        string res;
        while (n>0) {
            int i=n & 0xf;
            if (i>1 && i<=9) return "ERROR";
            char c;
            if (i==0) c='O';
            else if (i==1) c='I';
            else c=i-10+'A';
            res+=c;
            n>>=4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

