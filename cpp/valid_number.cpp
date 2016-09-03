#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

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

// Incomplete!!!
class Solution {
public:
	bool isNumeric(const char c)
	{
		return c >= '0' && c <= '9';
	}

	bool isWhiteSpace(const char c)
	{
		return (c == ' ' || c == '\t');
	}

    bool isNumber(const char *s) {
    	if (s == NULL) return false;
    	int len = strlen(s);

    	int b, e;

    	for (b = 0; b < len; b++)
    	{
    		if (!isWhiteSpace(s[b])) break;
    	}

    	for (e = len - 1; e >= 0; e--)
    	{
    		if (!isWhiteSpace(s[e])) break;
    	}

    	if (b <= e && (s[b] == '-' || s[b] == '+')) b++;

    	if (b <= e)
    	{
			int i;
			for (i = b; i <= e; i++)
			{
				if (!isNumeric(s[i])) break;
			}

			if (i > e) return true;
			else if (s[i] == 'e')
			{
				int j;
				if (i == b) return false;
				if (i == e) return false;

				j = i + 1;
				if (s[i+1] == '-' || s[i+1] == '+')
					j++;
				if (j > e) return false;

				for (; j <= e; j++)
				{
					if (!isNumeric(s[j])) return false;
				}

				return true;
			}
			else if (s[i] == '.')
			{
				int j;
				if (i == b && i == e) return false;

				for (j = i + 1; j <= e; j++)
				{
					if (!isNumeric(s[j])) return false;
				}

				return true;
			}
			else
			{
				return false;
			}
		}
    	else
    	{
    		return false;
    	}
    }
};

int main()
{
	return 0;
}

