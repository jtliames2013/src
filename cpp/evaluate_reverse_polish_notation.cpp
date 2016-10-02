150. Evaluate Reverse Polish Notation  QuestionEditorial Solution  My Submissions
Total Accepted: 71093 Total Submissions: 288951 Difficulty: Medium
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Hide Company Tags LinkedIn
Hide Tags Stack
Hide Similar Problems (H) Basic Calculator (H) Expression Add Operators

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>

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

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
    	stack<int> s;

    	for (int i = 0; i < tokens.size(); i++)
    	{
			if (tokens[i].compare("+") == 0)
			{
				int r = s.top();
				s.pop();
				int l = s.top();
				s.pop();
				s.push(l+r);
			}
			else if (tokens[i].compare("-") == 0)
			{
				int r = s.top();
				s.pop();
				int l = s.top();
				s.pop();
				s.push(l-r);
			}
			else if (tokens[i].compare("*") == 0)
			{
				int r = s.top();
				s.pop();
				int l = s.top();
				s.pop();
				s.push(l*r);
			}
			else if (tokens[i].compare("/") == 0)
			{
				int r = s.top();
				s.pop();
				int l = s.top();
				s.pop();
				s.push(l/r);
			}
    		else
    		{
    			s.push(atoi(tokens[i].c_str()));
    		}
    	}
    	return s.top();
    }
};

2.

class Solution {
public:
    bool isop(string s) {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i=0; i<tokens.size(); i++) {
            if (isop(tokens[i])) {
                int num2=stk.top();
                stk.pop();
                int num1=stk.top();
                stk.pop();
                if (tokens[i]=="+") stk.push(num1+num2);
                else if (tokens[i]=="-") stk.push(num1-num2);
                else if (tokens[i]=="*") stk.push(num1*num2);
                else if (tokens[i]=="/") stk.push(num1/num2);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        
        return stk.top();
    }
};

int main()
{
	return 0;
}

