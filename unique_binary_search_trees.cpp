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
    int numTrees(int n) {
    	if (n<=0) return 1;
    	if (n==1) return 1;

    	int sum=0;
    	for (int i=0; i<n; i++)
    	{
    		sum += numTrees(i) * numTrees(n-1-i);
    	}

    	return sum;
    }
};

2. non-recursive

class Solution {

public:

    int numTrees(int n) {

        if (n==0 || n==1) return 1;

        vector<int> count(n+1, 0);

        count[0]=count[1]=1;

        for(int i=2; i<=n; i++) {

            for (int j=0; j<i; j++) {

                count[i]+=count[j]*count[i-1-j];

            }

        }

        return count[n];

    }

};

int main()
{
	return 0;
}

