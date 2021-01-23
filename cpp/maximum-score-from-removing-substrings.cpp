1717. Maximum Score From Removing Substrings
Medium

173

12

Add to List

Share
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res=0, mn=min(x, y), mx=max(x, y);
        char first=x>y?'a':'b', second=x>y?'b':'a';
        vector<char> stk, stk2;
        for (auto c:s) {
            if (c==second && !stk.empty() && stk.back()==first) {
                stk.pop_back();
                res+=mx;
            } else {
                stk.push_back(c);
            }
        }
        for (auto c:stk) {
            if (c==first && !stk2.empty() && stk2.back()==second) {
                stk2.pop_back();
                res+=mn;
            } else {
                stk2.push_back(c);
            }            
        }
        return res;
    }
};

