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
    int countDigitOne(int n) {
    	int count=0;
    	if (n<=0) return 0;
    	vector<unsigned long long> ones;
    	unsigned long long i=1;
    	// ones represents number of one digit between [0, 10^k)
    	ones.push_back(0); // [0.1)
    	ones.push_back(1); // [0, 10)
    	while (i < LONG_MAX) {
    		unsigned long long last=ones.back();
    		i *= 10;
    		ones.push_back(last*10+i);
    	}

    	i=1;
    	int index=0;
    	while (n/i > 0) {
    		i *= 10;
    		index++;
    	}
    	i /= 10;
    	index--;
    	int digit;
    	while (i>0) {
    		digit=n/i;
    		n=n%i;
    		if (digit==1) {
    			count+=ones[index]+n+1;
    		} else if (digit > 1){
    			count+=digit*ones[index] + i;
    		}

    		i/=10;
    		index--;
    	}

    	return count;
    }
};

int main()
{
	return 0;
}

