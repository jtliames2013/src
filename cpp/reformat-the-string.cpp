1417. Reformat The String
Easy

33

21

Add to List

Share
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.

class Solution {
public:
    string reformat(string s) {
        string letters, digits;
        for (auto c:s) {
            if (isdigit(c)) digits+=c;
            else letters+=c;
        }
        if (abs((int)letters.size()-(int)digits.size())>1) return "";
        if (letters.size()>digits.size()) {
            return convert(letters, digits);
        } else {
            return convert(digits, letters);
        }
    }
private:
    string convert(string& s, string& t) {
        string res;
        int m=s.size(), n=t.size(), i=0;
        for (; i<n; ++i) { res+=s[i]; res+=t[i]; }
        if (i<m) res+=s[i];
        return res;
    }
};

