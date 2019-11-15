301. Remove Invalid Parentheses 
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

这道题让我们移除最少的括号使得给定字符串为一个合法的含有括号的字符串，我们从小数学里就有括号，所以应该对合法的含有括号的字符串并不陌生，字符串中的左右括号数应该相同，而且每个右括号左边一定有其对应的左括号，而且题目中给的例子也说明了去除方法不唯一，我们需要找出所有合法的取法。参考了网上大神的解法，这道题首先可以用BFS来解，我们先把给定字符串排入队中，然后取出检测其是否合法，若合法直接返回，不合法的话，我们对其进行遍历，对于遇到的左右括号的字符，我们去掉括号字符生成一个新的字符串，如果这个字符串之前没有遇到过，将其排入队中，我们用哈希表记录一个字符串是否出现过。我们对队列中的每个元素都进行相同的操作，直到队列为空还没找到合法的字符串的话，那就返回空集，参见代码如下：

1. BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (isValid(s)) return { s };
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            int size=q.size();
            bool found=false;
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                for (int j=0; j<f.size(); ++j) {
                    if (f[j]=='(' || f[j]==')') {
                        string next=f.substr(0,j)+f.substr(j+1);
                        if (visited.find(next)==visited.end()) {
                            if (isValid(next)) {
                                res.push_back(next);
                                found=true;
                            } else {
                                q.push(next);
                            }
                            visited.insert(next);
                        }
                    }
                }
            }
            if (found) break;
        }
        
        return res;
    }
private:
    bool isValid(string& s) {
        int count=0;
        for (auto c:s) {
            if (c=='(') count++;
            else if (c==')') {
                if (count==0) return false;
                count--;
            }
        }
        return count==0;
    }
};

2. DFS
class Solution {
public:
    void dfs(vector<string>& res, string& s, string& expr, int start, int open, int close, int count) {
        if (count<0) return;
        if (start==s.size()) {
            if (open==0 && close==0) res.push_back(expr);
            return;
        }
        
        if (s[start]=='(' || s[start]==')') {
            int i=start+1;
            while (i<s.size() && s[i]==s[start]) i++;
            int len=expr.size();
            expr.append(i-start, s[start]);
            dfs(res, s, expr, i, open, close, count+(s[start]=='('?(i-start):(start-i)));
            expr.erase(len);
            
            if (s[start]=='(') {
                if (open>0) {
                    // remove extra '('
                    dfs(res, s, expr, start+1, open-1, close, count);
                }
            } else {
                if (close>0) {
                    // remove extra ')'
                    dfs(res, s, expr, start+1, open, close-1, count);
                }
            }
        } else {
            expr.push_back(s[start]);
            dfs(res, s, expr, start+1, open, close, count);
            expr.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        string expr;
        int open=0, close=0, count=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') count++;
            else if (s[i]==')') {
                if (count==0) close++;
                else count--;
            }
        }
        open=count;
        if (open==0 && close==0) {
            res.push_back(s);
            return res;
        }

        dfs(res, s, expr, 0, open, close, 0);
        return res;
    }
};

