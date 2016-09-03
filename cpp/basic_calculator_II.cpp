227. Basic Calculator II 
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

1. 由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了.

class Solution {
public:
    bool isDigit(char c) {
        return (c>='0' && c<='9');
    }
    bool isOp(char c) {
        return (c=='+' || c=='-' || c== '*' || c=='/');
    }
    void process(char op, int num, stack<int>& nums) {
        if (op=='+') {
            nums.push(num);
        } else if (op=='-') {
            nums.push(-num);
        } else if (op=='*' || op=='/') {
            int t=nums.top();
            nums.pop();
            int sum=(op=='*'?t*num:t/num);
            nums.push(sum);
        }
    }
    int calculate(string s) {
        stack<int> nums;
        int num=0;
        char op='+';
        for (int i=0; i<s.size(); i++) {
            if (isDigit(s[i])) {
                num=num*10+s[i]-'0';
            } else if (isOp(s[i])) {
				// apply previous operator
                process(op, num, nums);
                num=0;
                op=s[i];
            }
        }
        
        process(op, num, nums);

        int res=0;
        while (!nums.empty()) {
            res+=nums.top();
            nums.pop();
        }
        
        return res;
    }
};

class Solution {
public:
    void process(vector<int>& nums, int num, char op) {
        if (op=='+') nums.push_back(num);
        else if (op=='-') nums.push_back(-num);
        else {
            int n=nums.back();
            nums.pop_back();
            nums.push_back(op=='*'?n*num:n/num);
        }
    }
    bool isOp(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/';
    }
    
    int calculate(string s) {
        int res;
        vector<int> nums;
        int num=0;
        char op='+';
        
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                num=0;
                while (isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
            } else if (isOp(s[i])) {
                process(nums, num, op);
                op=s[i];
                i++;
            } else {
                i++;
            }
        }
        
        process(nums, num, op);
        res=0;
        for (int i=0; i<nums.size();i++) {
            res+=nums[i];
        }
        return res;
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

int main()
{
	return 0;
}

