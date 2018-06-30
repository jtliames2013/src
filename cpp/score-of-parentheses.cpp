856. Score of Parentheses
DescriptionHintsSubmissionsDiscussSolution
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

1.
class Solution {
public:
    int scoreOfParentheses(string S) {        
        vector<int> stk;
        stk.push_back(0);
        for (int i=0; i<S.size(); ++i) {
            if (S[i]=='(') {
                stk.push_back(0);
            } else {
                int b=stk.back();
                stk.pop_back();
                stk.back()+=b==0?1:2*b;
            }
        }
        return stk.back();
    }
};

2.
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res=0, level=0;
        for (int i=0; i<S.size(); ++i) {
            if (S[i]=='(') level++;
            else level--;
            if (S[i]=='(' && S[i+1]==')') res+=(1<<(level-1));
        }
        
        return res;
    }
};
