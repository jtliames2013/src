1573. Number of Ways to Split a String
Medium

124

15

Add to List

Share
Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
Example 2:

Input: s = "1001"
Output: 0
Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"
Example 4:

Input: s = "100100010100110"
Output: 12
 

Constraints:

3 <= s.length <= 10^5
s[i] is '0' or '1'.

class Solution {
public:
    int numWays(string s) {
        long n=s.size(), cnt=0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='1') cnt++;
        }
        if (cnt%3!=0) return 0;
        if (cnt==0) return (n-1)*(n-2)/2%mod;
        cnt/=3;
        long first=0, second=0, ones=0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='1') ones++;
            if (ones==cnt) first++;
            if (ones==2*cnt) second++;
        }
        return first*second%mod;
    }
private:
    const int mod=1e9+7;
};

