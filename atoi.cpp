#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
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

class Solution {
public:
	bool isNumeric(char c)
	{
		return c >= '0' && c <= '9';
	}

    int atoi(const char *str) {
    	if (str == NULL) return 0;

    	unsigned long long res = 0;
    	int len = strlen(str);
    	int i;
    	for (i = 0; i < len; i++)
    	{
    		if (str[i] != ' ')
    		{
    			break;
    		}
    	}

    	bool neg = false;
    	if (i < len)
    	{
    		if (str[i] == '-')
    		{
    			neg = true;
    			i++;
    		}
    		else if (str[i] == '+')
    		{
    			i++;
    		}
    	}

    	for (int j = i; j < len; j++)
    	{
    		if (isNumeric(str[j]))
    		{
    			if (neg == false && res > 0x7FFFFFFF)
				{
					break;
				}
				else if (neg == true && res >= 0x80000000 )
				{
					break;
				}

    			res *= 10;
    			res += str[j] - '0';
    		}
    		else
    		{
    			break;
    		}
    	}

    	if (neg == false && res > 0x7FFFFFFF)
		{
			res = 0x7FFFFFFF;
		}
		else if (neg == true && res >= 0x80000000 )
		{
			res = 0x80000000;
		}

    	if (neg) res = res * (-1);
    	return (int)res;
    }
};

int main()
{
	return 0;
}

