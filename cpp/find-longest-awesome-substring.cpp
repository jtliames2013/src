1542. Find Longest Awesome Substring
Hard

101

4

Add to List

Share
Given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it palindrome.

Return the length of the maximum length awesome substring of s.

 

Example 1:

Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
Example 2:

Input: s = "12345678"
Output: 1
Example 3:

Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
Example 4:

Input: s = "00"
Output: 2
 

Constraints:

1 <= s.length <= 10^5
s consists only of digits.

class Solution {
public:
    int longestAwesome(string s) {
        int res=0, n=s.size(), mask=0;
        vector<int> mp(1024, n);
        mp[0]=-1;
        for (int i=0; i<n; ++i) {
            mask^=(1<<(s[i]-'0'));
            res=max(res, i-mp[mask]);
            for (int j=0; j<10; ++j) {
                res=max(res, i-mp[mask^(1<<j)]);
            }
            mp[mask]=min(mp[mask], i);
        }

        return res;
    }
};
