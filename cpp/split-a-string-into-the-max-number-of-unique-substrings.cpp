1593. Split a String Into the Max Number of Unique Substrings
Medium

106

7

Add to List

Share
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 

Constraints:

1 <= s.length <= 16

s contains only lower case English letters.

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return dfs(s, st, 0);
    }
private:
    int dfs(string& s, unordered_set<string>& st, int start) {
        if (start==s.size()) return 0;
        int res=0;
        for (int i=start; i<s.size(); ++i) {
            string str=s.substr(start, i-start+1);
            if (st.find(str)==st.end()) {
                st.insert(str);
                res=max(res, 1+dfs(s, st, i+1));
                st.erase(str);
            }
        }
        return res;
    }
};

