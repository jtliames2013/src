#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <limits.h>

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

class Solution {
public:
    int numDecodings(string s) {
    	int len = s.size();
    	if (len == 0) return 0;

    	vector<int> count(len);

    	for (int i=len-1; i>=0; i--)
    	{
    		if (i < len-1)
    		{
    			count[i] = count[i+1];

    			if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6' && s[i+1] >= '0' ))
    			{
    				if (i < len-2)
    				{
    					count[i] += count[i+2];
    				}
    				else
    				{
    					count[i] += 1;
    				}
    			}
    			else if (s[i] == '0')
    			{
    				count[i] = 0;
    			}
    		}
    		else
    		{
    			if (s[i] == '0') count[i] = 0;
    			else count[i] = 1;
    		}
    	}

    	return count[0];
    }
};

int main()
{
	return 0;
}

