20. Valid Parentheses  QuestionEditorial Solution  My Submissions
Total Accepted: 126656 Total Submissions: 413593 Difficulty: Easy
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Hide Company Tags Google Airbnb Facebook Twitter Zenefits Amazon Microsoft Bloomberg
Hide Tags Stack String
Hide Similar Problems (M) Generate Parentheses (H) Longest Valid Parentheses (H) Remove Invalid Parentheses

class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (auto c:s) {
            if (c=='(' || c== '{' || c=='[') {
                stk.push_back(c);
            } else if (!stk.empty() && 
                     ((c==')' && stk.back()=='(') ||
                      (c=='}' && stk.back()=='{') ||
                      (c==']' && stk.back()=='['))) {
                  stk.pop_back();
            } else {
                return false;
            }
        }
        
        if (stk.empty()) return true;
        else return false;
    }
};

