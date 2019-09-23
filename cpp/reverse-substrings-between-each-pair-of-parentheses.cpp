1190. Reverse Substrings Between Each Pair of Parentheses
Medium

100

6

Favorite

Share
You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
 

Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.

class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        vector<int> open;
        for (int i=0; i<s.size(); ++i) {
            if (s[i]=='(') {
                open.push_back(res.size());
            } else if (s[i]==')') {
                int b=open.back();
                reverse(res.begin()+b, res.end());
                open.pop_back();                
            } else {
                res+=s[i];
            }
        }
        return res;
    }
};

2. No reverse, iterate zig-zag
class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        int n=s.size();
        vector<int> open, pos(n);
        for (int i=0; i<n; ++i) {
            if (s[i]=='(') {
                open.push_back(i);
            } else if (s[i]==')') {
                int b=open.back();                
                open.pop_back();
                pos[i]=b;
                pos[b]=i;
            }
        }
        
        for (int i=0, d=1; i<n; i+=d) {
            if (s[i]=='(' || s[i]==')') {
                i=pos[i];
                d=-d;
            } else {
                res+=s[i];
            }
        }
        return res;
    }
};
