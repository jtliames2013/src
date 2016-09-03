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
#include <math.h>

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
	bool isValid(string s) {
		return (s.size()==1 || s[0]!='0');
	}

    bool isAdditiveNumber(string num) {
    	int size=num.size();

    	for (int i=0; i<size/2+1; i++) {
    		for (int j=i+1; j<size && j-i<=size/2+1; j++) {
    			if (!isValid(num.substr(0,i+1)) || !isValid(num.substr(i+1,j-i))) continue;

    			unsigned long long a = strtoull(num.substr(0,i+1).c_str(), NULL, 10);
    			unsigned long long b = strtoull(num.substr(i+1,j-i).c_str(), NULL, 10);

    			int index=j+1;
    			char buf[128];
    			while (1) {
    				unsigned long long c=a+b;
    				sprintf(buf, "%llu", c);
    				int len=strlen(buf);
    				if (len > size-index) {
    					break;
    				} else if (len==size-index) {
    					if (strcmp(buf, num.substr(index, size-index).c_str())==0) return true;
    					else break;
    				} else {
    					if (strncmp(buf, num.substr(index, size-index).c_str(), len)==0) {
    						a=b;
    						b=c;
    						index+=len;
    					} else {
    						break;
    					}
    				}
    			}
    		}
    	}

    	return false;
    }
};

int main()
{
	return 0;
}

