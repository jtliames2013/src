282. Expression Add Operators 
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

class Solution {
public:
    // last is either a single number for previous +/- or accumulated result for *
    // 1+2*3*4+5
    void dfs(vector<string>& res, string& num, string& expr, long long target, int start, long long last) {
        if (start==num.size()) {
            if (target==0) res.push_back(expr);
            return;
        }
        
        for (int i=start; i<num.size(); i++) {
            if (i>start && num[start]=='0') break; // no need to continue if the first is '0'
            string curr=num.substr(start, i-start+1);
            long long currNum=stoll(curr);
            if (expr.empty()) {
                expr+=curr;
                dfs(res, num, expr, target-currNum, i+1, currNum);
                expr.clear();
            } else {
                int pos=expr.size();
                expr+="+"+curr;
                dfs(res, num, expr, target-currNum, i+1, currNum);
                expr.erase(pos);
                expr+="-"+curr;
                dfs(res, num, expr, target+currNum, i+1, -currNum);
                expr.erase(pos);
                expr+="*"+curr;
                dfs(res, num, expr, target+last-last*currNum, i+1, last*currNum);
                expr.erase(pos);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string expr;
        dfs(res, num, expr, target, 0, 0);
        return res;
    }
};

