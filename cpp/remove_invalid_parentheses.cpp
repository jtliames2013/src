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
    bool isValid(string& s) {
        int count=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') count++;
            else if (s[i]==')') {
                count--;
                if (count<0) return false;
            }
        }
        return count==0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        deque<string> q;
        unordered_set<string> visited;
        q.push_back(s);
        
        while (!q.empty()) {
            int n=q.size();
            bool found=false;
            for (int i=0; i<n; i++) {
                string f=q.front();
                q.pop_front();
                if (isValid(f)) {
                    res.push_back(f);
                    found=true;
                }
                
                if (!found) {
                    for (int j=0; j<f.size(); j++) {
                        if (f[j]=='(' || f[j]==')') {
                            string next=f.substr(0, j)+f.substr(j+1);
                            if (visited.find(next)==visited.end()) {
                                q.push_back(next);
                                visited.insert(next);
                            }
                        }
                    }
                }
            }
            
            if (found) q.clear();
        }
        
        return res;
    }
};

3. DFS
class Solution {
public:
    void dfs(vector<string>& res, string& s, int start, string& path, int open, int close, int count) {
        if (count<0) return;
        if (start==s.size()) {
            if (open==0&&close==0) {
                res.push_back(path);
            }
            return;
        }
        
        if (s[start]!='(' && s[start]!=')') {
            path.push_back(s[start]);
            dfs(res, s, start+1, path, open, close, count);
            path.pop_back();
        } else if (s[start]=='(') {
            int i=1;
            while (start+i<s.size() && s[start+i]=='(') i++;
            int len=path.size();
            path.append(i, s[start]);
            dfs(res, s, start+i, path, open, close, count+i);
            path.erase(len);
            
            if (open>0) {
                dfs(res, s, start+1, path, open-1, close, count);
            }
        } else {
            int i=1;
            while (start+i<s.size() && s[start+i]==')') i++;
            int len=path.size();
            path.append(i, s[start]);
            dfs(res, s, start+i, path, open, close, count-i);
            path.erase(len);
            
            if (close>0) {
                dfs(res, s, start+1, path, open, close-1, count);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int count=0, open=0, close=0;
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
        
        string path;
        dfs(res, s, 0, path, open, close, 0);
        
        return res;
    }
};

