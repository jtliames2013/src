772. Basic Calculator III
Hard

349

135

Add to List

Share
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.

Amazon
|
8

Google
|
4

Microsoft
|
3

Uber
|
3

Facebook
|
2

Snapchat
|
2

Pinterest
|
3

Intuit
|
2

Salesforce
|
2

Apple
|
2

Jingchi
|
LeetCode

Pocket Gems
|
LeetCode

Hulu
|
LeetCode

Houzz
|
LeetCode

DoorDash
|
LeetCode

class Solution {
public:
    int calculate(string s) {
        int i=0;
        return parseExpr(s, i);
    }
private:
    long parseExpr(string& s, int& i) {
        long res=0, num;
        vector<long> nums;
        char op='+';
        for (; i<s.size(); ) {            
            if (isdigit(s[i])) {
                num=0;
                while(i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                process(nums, num, op);
            } else if (isop(s[i])) {
                op=s[i];
                i++;                
            } else if (s[i]=='(') {
                i++; // skip (
                num=parseExpr(s, i);
                process(nums, num, op);
                i++; // skip )
            } else if (s[i]==')') {
                break;  
            } else {
                i++;
            }
        }
        
        for (auto& i:nums) res+=i;
        return res;
    }

    void process(vector<long>& nums, long num, char op) {
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

