468. Validate IP Address Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5399
Total Submissions: 26611
Difficulty: Medium
Contributors:
Cyber233
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
Subscribe to see which companies asked this question.

Hide Tags String

class Solution {
public:
    string validIPAddress(string IP) {
        int type; //0 - IPv4, 1 - IPv6
        int len[2]={4, 8};
        char delim[2]={'.', ':'};
        string res[3]={"IPv4", "IPv6", "Neither"};
        
        if (IP.find('.')!=string::npos) {
            type=0;
        } else if (IP.find(':')!=string::npos) {
            type=1;
        } else {
            return res[2];
        }
        
        if (IP.back()=='.' || IP.back()==':') return res[2];
        istringstream iss(IP);
        int l=0;
        string val;
        while (getline(iss, val, delim[type])) {
            l++;
            if (l>len[type] || val.empty()) return res[2];
            
            if (type==0) {
                if (val.size()>3) return res[2];
                int num=0;
                for (int i=0; i<val.size(); i++) {
                    if (!isdigit(val[i])) return res[2];
                    num*=10;
                    num+=val[i]-'0';
                }
                if (num>255 || (val.size()>1 && val[0]=='0')) return res[2];
            } else if (type==1) {
                if (val.size()>4) return res[2];
                for (int i=0; i<val.size(); i++) {
                    if (!(isdigit(val[i]) || (val[i]>='a' && val[i]<='f') || (val[i]>='A' && val[i]<='F'))) return res[2];
                }
            }
        }
        
        return l==len[type]?res[type]:res[2];
    }
};

