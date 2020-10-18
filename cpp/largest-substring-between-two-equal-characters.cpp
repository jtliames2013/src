1624. Largest Substring Between Two Equal Characters
Easy

18

0

Add to List

Share
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
Example 4:

Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
 

Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res=-1;
        unordered_map<char, int> mp;
        for (int i=0; i<s.size(); ++i) {
            if (mp.find(s[i])!=mp.end()) {
                res=max(res, i-mp[s[i]]-1);
            } else {
                mp[s[i]]=i;
            }
        }
        return res;
    }
};

