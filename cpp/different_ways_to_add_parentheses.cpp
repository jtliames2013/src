241. Different Ways to Add Parentheses 
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

class Solution {
public:
    bool isop(char c) {
        if (c=='+' || c=='-' || c=='*' || c=='/') return true;
        return false;
    }
    
    int calc(int num1, int num2, char op) {
        switch (op) {
            case '+': return num1+num2;
            case '-': return num1-num2;
            case '*': return num1*num2;
            case '/': return num1/num2;
            default: return 0;
        }
    }

    vector<int> diffWaysToCompute(string& input, int start, int end) {
        if (start>end) return vector<int>();
        vector<int> res;
        for (int i=start; i<end; i++) {
            if (isop(input[i])) {
                vector<int> left=diffWaysToCompute(input, start, i-1);
                vector<int> right=diffWaysToCompute(input, i+1, end);
                for (int j=0; j<left.size(); j++) {
                    for (int k=0; k<right.size(); k++) {
                        res.push_back(calc(left[j], right[k], input[i]));
                    }
                }
            }
        }
        
        if (res.empty()) res.push_back(stoi(input.substr(start, end-start+1)));
        return res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute(input, 0, input.size()-1);
    }
};

