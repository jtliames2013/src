640. Solve the Equation
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"

class Solution {
public:
    pair<int,int> parse(string expr) {
        int coeff=0, val=0;
        int sign=1, num;
        for (int i=0; i<expr.size(); ) {
            if (expr[i]=='-') {
                sign=-1;
                i++;
            } else if (expr[i]=='+') {
                sign=1;
                i++;
            } else if (expr[i]=='x') {
                coeff+=sign;
                i++;
            } else if (isdigit(expr[i])) {
                num=0;
                while (i<expr.size() && isdigit(expr[i])) {
                    num=num*10+expr[i]-'0';
                    i++;
                }
                if (i<expr.size() && expr[i]=='x') {
                    coeff+=sign*num;
                    i++;
                } else {
                    val+=sign*num;
                }
            }
        }        
        return {coeff, val};
    }
    
    string solveEquation(string equation) {
        int pos=equation.find_first_of('=');
        if (pos==string::npos) return "No solution";
        
        string lhs=equation.substr(0, pos);
        string rhs=equation.substr(pos+1);
        pair<int,int> l=parse(lhs);
        pair<int,int> r=parse(rhs);
        int coeff=l.first-r.first;
        int val=r.second-l.second;
        if (coeff==0) {
            if (val==0) return "Infinite solutions";
            else return "No solution";
        }
        return "x="+to_string(val/coeff);
    }
};

