161. One Edit Distance
Medium

508

94

Add to List

Share
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

Facebook
|
6

Twitter
|
2

Amazon
|
3

Microsoft
|
2

Google
|
3

Uber
|
3

Snapchat
|
2

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size(),  n=t.size(), delta=abs(m-n), len=min(m, n);
        if (delta>1) return false;
        if (delta==1) {
            for (int i=0; i<len; ++i) {
                if (s[i]!=t[i]) {
                    return m>n?s.substr(i+1)==t.substr(i):s.substr(i)==t.substr(i+1);
                }
            }
            return true;
        } else {
            int count=0;
            for (int i=0; i<len; ++i) {
                if (s[i]!=t[i]) {
                    count++;
                    if (count>1) return false;
                }
            }
            return count==1;
        }
    }
};

