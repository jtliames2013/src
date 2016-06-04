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
    string longestPalindrome(string s) {
    	int start, end;
    	int length=0;
    	int finalStart, finalEnd;

    	for (int i=0; i<s.size(); i++) {
    		for (int j=0; j<2; j++) {
    			if (j==0) {
    				start=i;
    				end=i;
    			} else if (j==1) {
    				start=i-1;
    				end=i;
    			}

				while (start>=0 && end<s.size()) {
					if (s[start]==s[end]) {
						start--;
						end++;
					} else {
						break;
					}
				}

				if (length < end-1-(start+1)+1) {
					length = end-1-(start+1)+1;
					finalStart=start+1;
					finalEnd=end-1;
				}
    		}
    	}

    	return s.substr(finalStart, finalEnd-finalStart+1);
    }
};

int main()
{
	return 0;
}


