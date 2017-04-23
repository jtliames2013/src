150. Evaluate Reverse Polish Notation  QuestionEditorial Solution  My Submissions
Total Accepted: 71093 Total Submissions: 288951 Difficulty: Medium
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Hide Company Tags LinkedIn
Hide Tags Stack
Hide Similar Problems (H) Basic Calculator (H) Expression Add Operators

class Solution {
public:
    bool isop(string s) {
        if (s=="+" || s=="-" || s=="*" || s=="/") return true;
        return false;
    }
    
    int calc(int num1, int num2, string op) {
        if (op=="+") return num1+num2;
        else if (op=="-") return num1-num2;
        else if (op=="*") return num1*num2;
        else if (op=="/") return num1/num2;
        else return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto n:tokens) {
            if (!isop(n)) stk.push(stoi(n));
            else {
                int num2=stk.top();
                stk.pop();
                int num1=stk.top();
                stk.pop();
                stk.push(calc(num1, num2, n));
            }
        }
        return stk.top();
    }
};

