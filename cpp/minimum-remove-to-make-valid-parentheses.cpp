1249. Minimum Remove to Make Valid Parentheses
Medium

128

3

Favorite

Share
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int n=s.size();
        vector<int> stk;
        for (int i=0; i<n; ++i) {
            if (s[i]=='(') stk.push_back(i);
            else if (s[i]==')') {
                if (stk.empty() || s[stk.back()]!='(') stk.push_back(i);
                else stk.pop_back();
            }
        }
        
        for (int i=0, j=0; i<n; ++i) {
            if (j<stk.size() && i==stk[j]) j++;
            else res+=s[i];
        }
        return res;
    }
};

