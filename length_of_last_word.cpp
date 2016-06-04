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
    int lengthOfLastWord(const char *s) {
    	if (s == NULL) return 0;
    	int len = strlen(s);

    	int end, i;
    	for (end = len - 1; end >= 0; end--)
    	{
    		if (s[end] != ' ') break;
    	}

    	if (end < 0) return 0;

    	for (i = end; i >= 0; i--)
    	{
    		if (s[i] == ' ') break;
    	}

    	return end - i;
    }
};

int main()
{
	return 0;
}

