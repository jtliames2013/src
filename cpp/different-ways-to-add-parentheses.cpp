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
    vector<int> diffWaysToCompute(string input) {
        return dfs(input, 0, input.size()-1);
    }
private:
    vector<int> dfs(string& input, int start, int end) {
        if (start>end) return vector<int>();
        vector<int> res;

        for (int i=start; i<=end; ++i) {
            if (isop(input[i])) {
                vector<int> left=dfs(input, start, i-1);
                vector<int> right=dfs(input, i+1, end);
                for (int j=0; j<left.size(); ++j) {
                    for (int k=0; k<right.size(); ++k) {
                        res.push_back(calc(left[j], right[k], input[i]));
                    }
                }
            }
        }
        
        if (res.empty()) return { stoi(input.substr(start, end-start+1)) };
        else return res;
    }

    bool isop(char c) {
        return c=='+' || c=='-' || c=='*';
    }
    
    int calc(int l, int r, char op) {
        switch (op) {
            case '+': return l+r;
            case '-': return l-r;
            case '*': return l*r;
            default: return 0;
        }
    }
};
