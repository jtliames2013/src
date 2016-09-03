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
	unsigned long long min(unsigned long long a, unsigned long long b, unsigned long long c) {
		if (a > b) {
			return b>c? c : b;
		} else {
			return a>c? c : a;
		}
	}

	int nthUglyNumber(int n) {
    	if (n==1) return 1;

    	vector<unsigned long long> l1, l2, l3;
    	int l1index=0, l2index=0, l3index=0;

    	l1.push_back(2);
    	l2.push_back(3);
    	l3.push_back(5);

    	while (l1.size() < n) {
    		unsigned long long m = min(l1[l1index], l2[l2index], l3[l3index]);
    		l1.push_back(m*2);
    		l2.push_back(m*3);
    		l3.push_back(m*5);
    		if (l1[l1index]==m) l1index++;
    		if (l2[l2index]==m) l2index++;
    		if (l3[l3index]==m) l3index++;
    	}

    	return l1[n-1]/2;
    }
};

int main()
{
	return 0;
}


