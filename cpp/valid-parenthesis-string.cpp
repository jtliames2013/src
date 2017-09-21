678. Valid Parenthesis String
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

class Solution {
public:
    bool checkValidString(string s) {
        int count=0, star=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='*') star++;
            else if (s[i]=='(') count++;
            else if (s[i]==')') {
                if (count==0) {
                    if (star==0) return false;
                    star--;
                } else {
                    count--;
                }
            }
        }
        if (count>star) return false;
        
        count=0, star=0;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i]=='*') star++;
            else if (s[i]=='(') {
                count++;
                if (count>star) return false;
            } else if (s[i]==')') count--;
        }
        return true;
    }
};

