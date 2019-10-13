1081. Smallest Subsequence of Distinct Characters
Medium

182

36

Favorite

Share
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"
Example 2:

Input: "abcd"
Output: "abcd"
Example 3:

Input: "ecbacba"
Output: "eacb"
Example 4:

Input: "leetcode"
Output: "letcod"
 

Note:

1 <= text.length <= 1000
text consists of lowercase English letters.

class Solution {
public:
    string smallestSubsequence(string text) {
        string res;
        vector<int> count(26);
        vector<char> visited(26);
        for (auto c:text) count[c-'a']++;
        for (auto c:text) {
            count[c-'a']--;
            if (visited[c-'a']==false) {
                while (!res.empty() && c<res.back() && count[res.back()-'a']>0) {
                    visited[res.back()-'a']=false;
                    res.pop_back();
                }
                visited[c-'a']=true;
                res.push_back(c);
            }
        }
        return res;
    }
};
