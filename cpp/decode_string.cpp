394. Decode String  QuestionEditorial Solution  My Submissions
Total Accepted: 760 Total Submissions: 2462 Difficulty: Medium
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
Subscribe to see which companies asked this question

Hide Tags Depth-first Search Stack

class Solution {
public:
    string dfs(string& s, int start, int *end) {
        string res;
        for (size_t i=start; i<s.size(); ) {
            if (isalpha(s[i])) {
                res.push_back(s[i]);
                i++;
            } else if (isdigit(s[i])) {
                int num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                int last;
                string str=dfs(s, i, &last);
                for (int j=0; j<num; j++) {
                    res+=str;
                }
                i=last+1;
            } else if (s[i]==']') {
                *end=i;
                break;
            } else {
                i++;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int last;
        return dfs(s, 0, &last);
    }
};
