28. Implement strStr()  
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Hide Company Tags Pocket Gems Microsoft Apple Facebook
Hide Tags Two Pointers String
Hide Similar Problems (H) Shortest Palindrome

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
    int strStr(char *haystack, char *needle) {
    	if (haystack == NULL || needle == NULL) return -1;
    	if (*haystack == '\0' && *needle == '\0') return 0;

    	int hlen = strlen(haystack);
    	int nlen = strlen(needle);
    	char *h, *n;
    	char *first = haystack;
    	while (*first)
    	{
    		h = first;
    		n = needle;
    		// make leetcode pass
    		if (hlen - (first - haystack) < nlen) break;

    		while (*h && *n)
    		{
    			if (*h != *n) break;
    			h++;
    			n++;
    		}
    		if (*n == '\0')
    		{
    			return (first - haystack);
    		}

    		first++;
    	}

    	return -1;
    }
};

int main()
{
	return 0;
}

