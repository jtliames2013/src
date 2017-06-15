224. Basic Calculator 
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

1. Basically add or minus from left to right, when inside (), the sign is toggled depending on operator before
(). E.g., 1+(2-3), 1-(2-3)
class Solution {
public:
    int calculate(string s) {
        int res=0;
        // one for add first number, one for multiple operator sign
        vector<int> sign(2,1);
        
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                int num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';  
                    i++;
                }
                res+=num*sign.back();
                sign.pop_back();
            } else if (s[i]==')') {
                sign.pop_back();
                i++;
            } else if (s[i]!=' ') {
                sign.push_back(sign.back()*(s[i]=='-'?-1:1));
                i++;
            } else {
                i++;
            }
        }
        return res;
    }
};

2. Use recursion on ()
class Solution {
public:
    int recur(string& s, int start, int *newIdx) {
        int sum=0, sign=1, idx;
        
        for (int i=start; i<s.size();) {
            if (isdigit(s[i])) {
                int num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                sum+=sign*num;
            } else if (s[i]=='+' || s[i]=='-') {
                sign=s[i]=='+'?1:-1;
                i++;
            } else if (s[i]=='(') {
                sum+=sign*recur(s, i+1, &idx);
                i=idx+1;
            } else if (s[i]==')') {
                *newIdx=i;
                return sum;
            } else {
                i++;
            }
        }
        
        return sum;
    }
    int calculate(string s) {  
        s="("+s+")";
        int idx;
        return recur(s, 0, &idx);
  }
};

