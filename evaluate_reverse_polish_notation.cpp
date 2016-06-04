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

int main()
{
	return 0;
}

