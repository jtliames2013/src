439. Ternary Expression Parser
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"

Snapchat
|
LeetCode

1. DFS
class Solution {
public:
    string parseTernary(string& expression, int start, int& last) { 
        int l;
        for (int i=start; i<expression.size(); i++) {
            if (expression[i]=='?') {
                string left=parseTernary(expression, i+1, l);
                string right=parseTernary(expression, l+1, l);
                last=l;
                return expression.substr(start, i-start)=="T"?left:right;
            } else if (expression[i]==':') {
                last=i;
                return expression.substr(start, i-start);
            }
        }
        last=expression.size();
        return expression.substr(start);
    }
    
    string parseTernary(string expression) {
        int last;
        return parseTernary(expression, 0, last);
    }
};

2. Stack, assume expression is single character
class Solution {
public:
    string parseTernary(string expression) {
        int n=expression.size();
        if (n==0) return expression;
        stack<char> stk;
        for (int i=n-1; i>=0; i--) {
            if (!stk.empty() && stk.top()=='?') {
                stk.pop();
                char left=stk.top();
                stk.pop();
                stk.pop();
                char right=stk.top();
                stk.pop();
                stk.push(expression[i]=='T'?left:right);
            } else {
                stk.push(expression[i]);
            }
        }
        
        return string(1,stk.top());
    }
};
