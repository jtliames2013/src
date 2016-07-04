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

    bool isOp(string s) {

        return (s=="+" || s=="-" || s=="*" || s=="/");

    }

    

    string calc(string &l, string &r, string &op) {

        int res;

        int lhs=atoi(l.c_str());

        int rhs=atoi(r.c_str());

        if (op=="+") res=lhs+rhs;

        else if (op=="-") res=lhs-rhs;

        else if (op=="*") res=lhs*rhs;

        else res=lhs/rhs;

        

        return to_string(res);

    }

    

    int evalRPN(vector<string>& tokens) {

        int res;

        stack<string> stk;

        

        for (int i=0; i<tokens.size(); i++) {

            if (isOp(tokens[i])) {

                string r=stk.top();

                stk.pop();

                string l=stk.top();

                stk.pop();

                string val=calc(l, r, tokens[i]);

                stk.push(val);

            } else {

                stk.push(tokens[i]);

            }

        }

        

        res=atoi(stk.top().c_str());

        return res;

    }

};


int main()
{
	return 0;
}

