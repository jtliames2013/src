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
	void swap(string &s, int l, int r)
	{
		char temp;
		while (l < r)
		{
			temp = s[l];
			s[l] = s[r];
			s[r] = temp;
			l++;
			r--;
		}
	}

	bool isSpace(char c)
	{
		return (c == ' ' || c == '\t');
	}

    void reverseWords(string &s) {
    	int len = s.size();
    	if (len == 0) return;

    	swap(s, 0, len - 1);

    	bool foundStart = false;
    	int l;
    	for (int i = 0; i < len; i++)
    	{
    		if (!isSpace(s[i]) && foundStart == false)
    		{
    			foundStart = true;
    			l = i;
    		}
    		else if (isSpace(s[i]) && foundStart == true)
    		{
    			foundStart = false;
    			swap(s, l, i - 1);
    		}
    	}

    	if (foundStart == true)
    	{
    		swap(s, l, len - 1);
    	}

    	int start = 0;
    	bool leading = true;
    	bool hasSpace = false;
    	for (int i = 0; i < len; i++)
    	{
    		if (leading == true && !isSpace(s[i]))
    		{
    			leading = false;
    			s[start] = s[i];
    			start++;
    		}
    		else if (!isSpace(s[i]))
    		{
    			s[start] = s[i];
    			start++;
    			hasSpace = false;
    		}
    		else if (leading == false && isSpace(s[i]) && hasSpace == false)
    		{
    			hasSpace = true;
    			s[start] = s[i];
    			start++;
    		}
    	}

    	if (isSpace(s[start-1]))
		{
    		s[start-1] = '\0';
    		s.resize(start-1);
		}
    	else
    	{
    		s[start] = '\0';
    		s.resize(start);
    	}
    }
};

int main()
{
	return 0;
}

