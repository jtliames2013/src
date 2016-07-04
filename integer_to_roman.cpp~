#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
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
    string intToRoman(int num) {
    	string res;
    	char symbol[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    	int scale=1000;
    	for (int i=0; i<7; i+=2)
    	{
    		int digit=num/scale;
    		if (digit > 0)
    		{
    			if (digit<=3)
    			{
    				res.append(digit, symbol[i]);
    			}
    			else if (digit==4)
    			{
    				res.append(1, symbol[i]);
    				res.append(1, symbol[i-1]);
    			}
    			else if (digit==5)
    			{
    				res.append(1, symbol[i-1]);
    			}
    			else if (digit<=8)
    			{
    				res.append(1, symbol[i-1]);
    				res.append(digit-5, symbol[i]);
    			}
    			else if (digit==9)
    			{
    				res.append(1, symbol[i]);
    				res.append(1, symbol[i-2]);
    			}
    		}
    		num = num % scale;
    		scale /= 10;
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

