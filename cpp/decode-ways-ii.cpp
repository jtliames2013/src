639. Decode Ways II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.

class Solution {
public:
    int decode(string s) {
        if (s.size()==1) {
            if (s[0]=='*') return 9;
            else return s[0]=='0'?0:1;
        }
        
        if (s[0]=='*') {
            if (s[1]=='*') return 15; // 11-26 except 20
            else return s[1]<='6'?2:1;
        } else {
            if (s[1]=='*') return s[0]=='1'?9:(s[0]=='2'?6:0);
            else {
                if (s[0]=='1' || (s[0]=='2' && s[1]<='6')) return 1;
                else return 0;
            }
        }
    }
    
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        long a=1, b=decode(s.substr(0,1));
        for (int i=1; i<n; i++) {
            long c=a*decode(s.substr(i-1,2))+b*decode(s.substr(i,1));
            a=b;
            b=c%mod;
        }
        return b;
    }
private:
    const int mod = pow(10, 9) + 7;      
};

