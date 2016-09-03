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

    	for (int i = 0; ; i++)
    	{
    		for (int j = 0; ; j++)
    		{
    			if (needle[j] == NULL) return i;
    			if (haystack[i + j] == NULL) return -1;
    			if (haystack[i+j] != needle[j]) break;
    		}
    	}

    	return -1;
     }
};

2.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        
        for (int i=0; i<=m-n; i++) {
            int j;
            for (j=0; j<n; j++) {
                if (needle[j]!=haystack[i+j]) break;
            }
            if (j==n) return i;
        }
        
        return -1;   
    }
};

int main()
{
	return 0;
}

