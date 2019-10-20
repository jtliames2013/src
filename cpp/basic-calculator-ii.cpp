227. Basic Calculator II 
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

1. 由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了.

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        char op='+';
        int res=0, num;
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                process(nums, num, op);
            } else if (isop(s[i])) {
                op=s[i];
                i++;
            } else {
                i++;
            }
        }
        for (auto i:nums) res+=i;
        return res;
    }
private:
    void process(vector<int>& nums, int num, char op) {
        if (op=='+') nums.push_back(num);
        else if (op=='-') nums.push_back(-num);
        else {
            nums.back()=op=='*'?nums.back()*num:nums.back()/num;
        }
    }

    bool isop(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/';
    }
};

2. Use num to remember current number. If operator is * or /, then get next number and apply operator.
Otherwise, current number can be added or substracted with previous number. (it cannot add or minus next
number. e.g., 1+2*3)
class Solution {
public:
    int calculate(string s) {
        int res=0;
        int num;
        char op;
        int sign=1;
        istringstream iss(s+"+");
        iss>>num;
        
        while (iss>>op) {
            if (op=='+' || op=='-') {
                res+=sign*num;
		// save sign for next time
                sign=(op=='+'?1:-1);
                iss>>num;
            } else {
                int n;
                iss>>n;
                if (op=='*') num*=n;
                else num/=n;
            }
        }
        
        return res;
    }
};

