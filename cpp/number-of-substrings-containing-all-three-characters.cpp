1358. Number of Substrings Containing All Three Characters
Medium

42

0

Add to List

Share
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), l=0, r=0, start=0, res=0;
        unordered_map<char, int> mp;
        int total=0;
        for (; r<n; ++r) {
            mp[s[r]]++;
            if (mp[s[r]]==1) total++;
            if (total==3) {
                while (total==3) {
                    mp[s[l]]--;
                    if (mp[s[l]]==0) total--;
                    l++;
                }
                res+=(l-start)*(n-r);
                start=l;
            }
        }
        return res;
    }
};

