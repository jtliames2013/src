405. Convert a Number to Hexadecimal   QuestionEditorial Solution  My Submissions
Total Accepted: 7909 Total Submissions: 19308 Difficulty: Easy Contributors: Admin
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.

Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation

class Solution {
public:
    string toHex(int num) {
        string res;
        unsigned int n=num;
        if (n==0) return "0";
        while (n>0) {
            int digit=n%16;
            if (digit<10) res.push_back(digit+'0');
            else res.push_back(digit-10+'a');
            n/=16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

2.
class Solution {
public:
    string toHex(int num) {
        string res;
        if (num==0) return "0";
        unsigned int n=num;
        char letter[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while (n!=0) {
            res=letter[n&0xf]+res;
            n>>=4;
        }
        return res;
    }
};
