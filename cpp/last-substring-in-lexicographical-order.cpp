1163. Last Substring in Lexicographical Order
Hard

72

169

Favorite

Share
Given a string s, return the last substring of s in lexicographical order.

 

Example 1:

Input: "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: "leetcode"
Output: "tcode"
 

Note:

1 <= s.length <= 4 * 10^5
s contains only lowercase English letters.


The solution must be in one of those n suffix candidates, and the main idea here is to eliminate those candidates we are 
certain not the solution, at last, the only one left is our solution.


class Solution {
public:
    string lastSubstring(string s) {
        int n=s.size(), i=0, j=1, k=0;
        while (j+k<n) {
            if (s[i+k]==s[j+k]) {
                k++;
                continue;
            } else if (s[i+k]>s[j+k]) {
                j=j+k+1;
            } else {
                i=max(i+k+1, j);
                j=i+1;
            }
            k=0;
        }
        return s.substr(i);
    }
};
